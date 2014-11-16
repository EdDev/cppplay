/*
 * dynamic_state_machine_test.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */



#include "CppUTest/TestHarness.h"

#include "dynamic_state_machine.h"
#include "card_states.h"



TEST_GROUP(dynamic_sm)
{
    DStateMachine *sm;
    State *stateNA;
    State *stateInit;
    State *stateReady;
    State *stateProv;
    State *stateFault;

    void setupStateMachine(DStateMachine *sMachine)
    {
        sMachine->setBaseState(stateNA);
        sMachine->mapDefault(NULL);
        sMachine->mapStateResult2NextState(stateNA,    State::RET_SUCCESS, stateInit);
        sMachine->mapStateResult2NextState(stateInit,  State::RET_SUCCESS, stateProv);
        sMachine->mapStateResult2NextState(stateInit,  State::RET_FAIL,    stateFault);
        sMachine->mapStateResult2NextState(stateProv,  State::RET_SUCCESS, stateReady);
        sMachine->mapStateResult2NextState(stateFault, State::RET_FAIL,    stateInit);
    }

    void createCardStates()
    {
        stateNA    = new StateNA();
        stateInit  = new StateInit();
        stateReady = new StateReady();
        stateProv  = new StateProv();
        stateFault = new StateFault();
    }

    void destroyCardStates()
    {
        delete stateNA;
        delete stateInit;
        delete stateReady;
        delete stateProv;
        delete stateFault;
    }

    void setup()
    {
        sm = new DStateMachine();
        createCardStates();

        setupStateMachine(sm);
    }

    void teardown()
    {
        destroyCardStates();
        delete sm;
    }
};


TEST(dynamic_sm, define_sm)
{
    DStateMachine *_sm = new DStateMachine();
    _sm->setBaseState(stateNA);
    _sm->mapDefault(NULL);
    _sm->mapStateResult2NextState(stateNA,    State::RET_SUCCESS, stateInit);
    _sm->mapStateResult2NextState(stateInit,  State::RET_SUCCESS, stateProv);
    _sm->mapStateResult2NextState(stateInit,  State::RET_FAIL,    stateFault);
    _sm->mapStateResult2NextState(stateProv,  State::RET_SUCCESS, stateReady);
    _sm->mapStateResult2NextState(stateFault, State::RET_FAIL,    stateInit);

    POINTERS_EQUAL(stateNA, _sm->getCurrentState());

    delete _sm;
}

TEST(dynamic_sm, state_switch_evExist_sNA__moved2_StateInit)
{
    State *state = sm->getCurrentState();

    //TODO: Ugly, it should not process the event here, but in the SM.
    //      Need to convert this into a function pointer (or find a better solution).
    sm->execEvent(state->evExist());

    POINTERS_EQUAL(stateInit, sm->getCurrentState());
}

TEST(dynamic_sm, state_switch_evInitFail_sInit__moved2_StateFault)
{
    sm->setBaseState(stateInit);

    State *state = sm->getCurrentState();
    sm->execEvent(state->evInitFail());

    POINTERS_EQUAL(stateFault, sm->getCurrentState());
}

TEST(dynamic_sm, unsupported_event_for_the_given_state__remain_in_state)
{
    State *state = sm->getCurrentState();

    sm->execEvent(state->evProvSuccess());

    POINTERS_EQUAL(stateNA, sm->getCurrentState());
}

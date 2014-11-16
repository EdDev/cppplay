/*
 * card_controller_test.cpp
 *
 * The Controller test utilizes both the Dynamic SM implementation and the CardController logic.
 * We use an inherited controller & card class to allow unit tests to be performed.
 *
 *  Created on: Nov 16, 2014
 *      Author: edwardh
 */


#include "CppUTest/TestHarness.h"

#include "card_controller.h"
#include "device.h"

#include "dynamic_state_machine.h"
#include "card_states.h"


// Implementation of CardController for testing purposes.
class CardController4Test : public CardController
{
public:
    void setInputEvent(CardController::eventID evID) {input_event_id = evID;}
    void setInputDev(int devID) {input_dev_id = devID;}

    virtual void run()
    {
        DStateMachine *sm = this->cardSM[input_dev_id];
        State *st         = sm->getCurrentState();

        if(CardController::EV_EXIST == input_event_id)
            sm->execEvent(st->evExist());
    }
private:
    CardController::eventID input_event_id;
    int                     input_dev_id;
};


// Implementation of Device for testing purposes.
class CardDevice : public Device
{
public:
    CardDevice(CardController *controller) : Device(controller), last_event_id(CardController::EV_NONE){}
    void sendEvent(CardController::eventID evID){last_event_id = evID;}

    CardController::eventID lastEvent() {return last_event_id;}
    CardController::eventID last_event_id;
};

TEST_GROUP(card_controller)
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
        sm  = new DStateMachine();
        createCardStates();
        setupStateMachine(sm);
    }

    void teardown()
    {
        destroyCardStates();
        delete sm;
    }
};

TEST(card_controller, create_controller)
{
    CardController *controller = new CardController4Test();
    delete controller;
}

TEST(card_controller, register_card_onto_controller__get_id)
{
    CardController *controller = new CardController4Test();

    Device card(controller);
    card.devID = controller->regCard(sm);

    LONGS_EQUAL(0, card.devID);

    delete controller;
}

TEST(card_controller, register_2cards_onto_controller__get_next_unique_id)
{
    CardController *controller = new CardController4Test();

    Device card1(controller);
    Device card2(controller);
    card1.devID = controller->regCard(sm);
    card2.devID = controller->regCard(sm);

    LONGS_EQUAL(1, card2.devID);

    delete controller;
}

TEST(card_controller, card_triggers_an_event__controller_executes_sm_event)
{
    CardController *controller = new CardController4Test();

    CardDevice card(controller);
    card.devID = controller->regCard(sm);
    card.sendEvent(CardController::EV_EXIST);

    // Inject input (Event ID & Device ID)
    ((CardController4Test*)controller)->setInputEvent(card.lastEvent());
    ((CardController4Test*)controller)->setInputDev(card.devID);

    controller->run();

    POINTERS_EQUAL(stateInit, sm->getCurrentState());

    delete controller;
}

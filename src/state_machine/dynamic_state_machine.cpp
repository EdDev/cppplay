/*
 * dynamic_state_machine.cpp
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */


#include "dynamic_state_machine.h"



void DStateMachine::setBaseState(State *st)
{
    this->state = st;
}


void DStateMachine::mapDefault(State *default_nextState)
{
    this->default_next_state = default_nextState;
}


void DStateMachine::mapStateResult2NextState(State *st, State::stateResult ret_st, State *nextSt)
{
    if(ret_st < State::RET_COUNT)
        st->stateMap[ret_st] = nextSt;
}


void DStateMachine::execEvent(State::stateResult result)
{
    State *nextState = this->state->stateMap[result];

    if(NULL != nextState)
        this->state = nextState;
}

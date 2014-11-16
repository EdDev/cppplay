/*
 * card_states.h
 *
 * This file contains specific states with their relevant events (as methods).
 * For each state, an event will execute the relevant method,
 * performing some action and returning a result.
 * Note: In the below definition, no actions are performed and each method
 *       returns a specific result. In real usage, an action/method may return
 *       with different results.
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */

#ifndef STATE_MACHINE_CARD_STATES_H_
#define STATE_MACHINE_CARD_STATES_H_

#include "state.h"


class StateNA : public State
{
public:
    virtual stateResult evExist()      {return RET_SUCCESS;}
};

class StateInit : public State
{
public:
    virtual stateResult evInitSuccess(){return RET_SUCCESS;}
    virtual stateResult evInitFail()   {return RET_FAIL;}
};

class StateProv : public State
{
public:
    virtual stateResult evProvSuccess(){return RET_SUCCESS;}
    virtual stateResult evProvFail()   {return RET_FAIL;}
};

class StateReady : public State
{
public:
};

class StateFault : public State
{
public:
    virtual stateResult evInitSuccess(){return RET_SUCCESS;}
    virtual stateResult evInitFail()   {return RET_FAIL;}
};



#endif /* STATE_MACHINE_CARD_STATES_H_ */

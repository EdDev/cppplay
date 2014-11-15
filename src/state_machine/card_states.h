/*
 * card_states.h
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

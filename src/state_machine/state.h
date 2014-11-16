/*
 * state.h
 *
 * Description:
 * The State interface defines the available events with their default action.
 * (Here the defaults are to do nothing and return a FAIL response)
 * In addition, it contains the storage of the state map (mapping result to next state).
 * (Each state has such a map which is populated by the SM during configuration)
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */

#ifndef STATE_MACHINE_STATE_H_
#define STATE_MACHINE_STATE_H_

#include "string.h"

class State
{
public:
    State(){memset(stateMap, 0, sizeof(stateMap));}
    virtual ~State(){}

    // RET_COUNT must be left last, representing the number of possible results.
    enum stateResult {RET_SUCCESS=0, RET_FAIL, RET_COUNT};

    virtual stateResult evExist()      {return RET_FAIL;}
    virtual stateResult evInitSuccess(){return RET_FAIL;}
    virtual stateResult evInitFail()   {return RET_FAIL;}
    virtual stateResult evProvSuccess(){return RET_FAIL;}
    virtual stateResult evProvFail()   {return RET_FAIL;}

    State *stateMap[RET_COUNT];
};


#endif /* STATE_MACHINE_STATE_H_ */

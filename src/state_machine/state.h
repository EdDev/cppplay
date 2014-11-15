/*
 * state.h
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

    // RET_COUNT must be left last, counting the number of possible results.
    enum stateResult {RET_SUCCESS=0, RET_FAIL, RET_COUNT};

    virtual stateResult evExist()      {return RET_FAIL;}
    virtual stateResult evInitSuccess(){return RET_FAIL;}
    virtual stateResult evInitFail()   {return RET_FAIL;}
    virtual stateResult evProvSuccess(){return RET_FAIL;}
    virtual stateResult evProvFail()   {return RET_FAIL;}

    State *stateMap[RET_COUNT];
};


#endif /* STATE_MACHINE_STATE_H_ */

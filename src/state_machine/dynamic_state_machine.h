/*
 * dynamic_state_machine.h
 *
 * A State Machine implementation with configurable state transitions.
 * It maintains state decoupling, allowing it to scale and support multiple setups.
 *
 * Setup/Definition logic:
 * - Create a State Machine.
 * - Create states.
 * - Set the SM initial state.
 * - Set the SM default behavior: Action to take if no map is found.
 *   (NULL specifies to remain in the same state)
 * - Map State & Result to the next State. (state, result, nextState)
 *   Receiving an event wile in state, triggers a state operation, resulting in a StateResult.
 *   SM State is changed to the nextState based on the result.
 *
 * Operation:
 * - Usually called from a controller that receives events in an asynchronous mode.
 *   Usage example:
 *   State *state = sm->getCurrentState();
 *   sm->execEvent(state->evExist());
 *   // At this stage sm->getCurrentState() will return a new state.
 *
 *
 *  Created on: Nov 15, 2014
 *      Author: edwardh
 */

#ifndef DYNAMIC_STATE_MACHINE_H_
#define DYNAMIC_STATE_MACHINE_H_

#include "state.h"

class DStateMachine
{
public:
    // SM Setup //
    void setBaseState(State *st);

    void mapDefault(State *default_nextState);

    void mapStateResult2NextState(State *st, State::stateResult ret_st, State *nextSt);

    // SM Operations //
    void execEvent(State::stateResult result);     //TODO: Ugly, it should not process the event at the calee, but in the SM.
                                                   //      Need to convert this into a function pointer (or find a better solution).

    State *getCurrentState(){return state;};

private:
    State *state;
    State *default_next_state;

    /*
     * Currently, the State MAP is maintained by each state independently.
     * Located at the State "interface" to decouple individual states from each other.
     * A different design approach could be to keep & manage the MAP here, in the SM, however
     * it will require a special data structure to be maintain.
     * It needs to be reconsidered again, some more thought should be put into this.
     */
};



#endif /* DYNAMIC_STATE_MACHINE_H_ */

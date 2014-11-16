/*
 * card_controller.h
 *
 * Description:
 * The controller is serving the cards (devices) by providing them means
 * to register to the controller with their SM and giving each a unique id for communication.
 *
 * regCard() is used for card registration.
 * run() is used for running the controller, usually in it's own task in an endless loop,
 * blocking on recv messages.
 *
 *  Created on: Nov 16, 2014
 *      Author: edwardh
 */

#ifndef STATE_MACHINE_CARD_CONTROLLER_H_
#define STATE_MACHINE_CARD_CONTROLLER_H_

#include "dynamic_state_machine.h"

class CardController
{
public:
    CardController();
    virtual ~CardController(){}

    enum eventID {EV_NONE, EV_EXIST, EV_INIT_SUCCESS, EV_INIT_FAIL, EV_PROV_SUCCESS, EV_PROV_FAIL, EV_COUNT};

    int regCard(DStateMachine *sm);

    virtual void run();

    static const int MAX_SUPPORTED_CARDS = 32;

protected:
    DStateMachine *cardSM[MAX_SUPPORTED_CARDS];
    int            number_of_registered_cards;
};


#endif /* STATE_MACHINE_CARD_CONTROLLER_H_ */

/*
 * card_controller.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: edwardh
 */

#include "card_controller.h"

#include <string.h>

#ifndef FOREVER
#define FOREVER() for(;;)
#endif

CardController::CardController() : number_of_registered_cards(0)
{
    memset(this->cardSM, 0, MAX_SUPPORTED_CARDS);
}

int CardController::regCard(DStateMachine *sm)
{
    this->cardSM[number_of_registered_cards] = sm;
    return number_of_registered_cards++;
}

void CardController::run()
{
//    Do here some Init stuff...

//    Enter the main loop, receive messages from Device/s (Cards),
//    identify the sender by devID and lookup his SM.
//    We are left with executing the event on the SM.
//
//    FOREVER()
//    {
//        msg = recv_msg();
//        switch (msg->event)
//        {
//        case EV_EXIST:
//                this->cardSM[msg->devID]->execEvent(...event...);
//        }
//    }
}


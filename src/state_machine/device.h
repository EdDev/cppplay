/*
 * device.h
 *
 * Description:
 * A device is a generalization of a card, which has a reference to a controller
 * and gets from the controller an ID (identifying it at the controller).
 *
 * A device can send an event to the controller through the sendEvent method.
 *
 *  Created on: Nov 16, 2014
 *      Author: edwardh
 */

#ifndef STATE_MACHINE_DEVICE_H_
#define STATE_MACHINE_DEVICE_H_

#include "card_controller.h"

class Device
{
public:
    Device(CardController *controller) : devID(-1), ctrl(controller) {}
    virtual ~Device(){};

    virtual void sendEvent(CardController::eventID evID)
    {
        (void)evID;
        /*
         * Build a message and send it to the controller.
         * msg->event = evID;
         * msg->devID = this->devID;
         * send_msg_to_controller(msg);
         */
    }

    int devID;

//    // For debug only (actually for tests. TODO: Should be cleaned up and moved to the test.
//    CardController::eventID lastEvent() {return last_event_id;}
//    CardController::eventID last_event_id;
private:
    CardController *ctrl;
};


#endif /* STATE_MACHINE_DEVICE_H_ */

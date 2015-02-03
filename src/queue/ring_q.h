/*
 * ring_q.h
 *
 */

#ifndef QUEUE_RING_Q_H_
#define QUEUE_RING_Q_H_

#include "rte_ring.h"

class queue
{
public:
	queue(unsigned int q_size, unsigned int type = 0)
	{
		ring = rte_ring_create("test", q_size, SOCKET_ID_ANY, type);
	}
	virtual ~queue()
	{
		free(ring);
	}
	unsigned int enqueue(void * const * obj_array){(void)obj_array; return 0;}
	unsigned int dequeue(void ** obj_array){(void)obj_array; return 0;}

	unsigned int obj_count(){return rte_ring_count(ring);};
private:
	rte_ring *ring;
};


class spc_queue : public queue
{
public:
	spc_queue(std::size_t q_size) : queue(q_size, RING_F_SP_ENQ | RING_F_SC_DEQ) {}
private:
};

class mpc_queue : public queue
{

};



#endif /* QUEUE_RING_Q_H_ */

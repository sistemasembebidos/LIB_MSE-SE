/*
 * EventQueues.c
 *
 *  Created on: 01/06/2014
 *      Author: Juan Manuel Cruz
 */

#include "..\inc\EventQueues.h"

// Driver Event Queue
#define eVENTqUEUEsIZE		20

struct EventQueueStruct {
	unsigned char Head;
	unsigned char Tail;
	unsigned char Count;
	EVENTtYPE Events[eVENTqUEUEsIZE];
} EventQueue;


void InitEventQueue (void)
{
	unsigned char count;

	EventQueue.Count = 0;
	EventQueue.Head = 0;
	EventQueue.Tail = 0;
	for (count = 0; count < eVENTqUEUEsIZE; count++)
		EventQueue.Events[count] = EVENTuNDEFINED;
}


void PutEventQueue (EVENTtYPE event)
{
	__disable_irq();

	EventQueue.Count++;
	EventQueue.Events[EventQueue.Head++] = event;
	if (EventQueue.Head == eVENTqUEUEsIZE)
		EventQueue.Head = 0;

	__enable_irq();
}


EVENTtYPE GetEventQueue(void)
{
	EVENTtYPE event;

	EventQueue.Count--;
	event = EventQueue.Events[EventQueue.Tail];
	EventQueue.Events[EventQueue.Tail++] = EVENTuNDEFINED;
	if (EventQueue.Tail == eVENTqUEUEsIZE)
		EventQueue.Tail = 0;

	return event;
}


unsigned char AnyEventQueue (void)
{
	return (EventQueue.Head != EventQueue.Tail);
}

/* StackLib */

#include "ListLib.h"
#ifndef _STACK_LIB_H
#define _STACK_LIB_H

typedef struct SNODE
{
    int ReceiptNumber;
	char *MovieTheaterName;
	LNODE *TicketList;
    struct SNODE *next_ptr;
} 
SNODE;

void push(SNODE **, LNODE *, int, char[]);
void pop(SNODE **);

#endif

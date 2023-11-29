/* Stack Library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackLib.h"

void push(SNODE **StackTop, LNODE *TicketList, int ReceiptNumber, char MTN[])
{
    SNODE *NewNode = malloc(sizeof(SNODE));
    NewNode->ReceiptNumber = ReceiptNumber;
	NewNode->TicketList =  TicketList;
	NewNode->MovieTheaterName = malloc(strlen(MTN) * sizeof(char) + 1);
	strcpy(NewNode->MovieTheaterName, MTN);
	NewNode->next_ptr = NULL;
	if (*StackTop == NULL)
	{
		*StackTop = NewNode;
	}
	else
	{
		NewNode->next_ptr = *StackTop;
		*StackTop = NewNode;
    }
}

void pop(SNODE **StackTop)
{
	if (*StackTop != NULL)
	{
		SNODE *TempPtr = (*StackTop)->next_ptr;

		free(*StackTop);
		*StackTop = TempPtr;
	}
}
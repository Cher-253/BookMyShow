/* Linked List Library */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListLib.h"

void InsertNode(LNODE **LLH, char Ticket[])
{
    int NodeAdded = 0;
    LNODE *TempPtr, *PrevPtr, *NewNode;
	PrevPtr = NULL;
	TempPtr = *LLH;
	while (TempPtr != NULL && (strcmp(Ticket, TempPtr->Ticket) > 0))
	{
		PrevPtr = TempPtr;
		TempPtr = TempPtr->next_ptr;
	}
	NewNode = malloc(sizeof(LNODE));
	strcpy(NewNode->Ticket, Ticket);
	NewNode->next_ptr = TempPtr;
	if (PrevPtr == NULL)
	{
		*LLH = NewNode;
	}
	else
	{
		PrevPtr->next_ptr = NewNode;
	}
}

void ReturnAndFreeLinkedListNode(LNODE **LLH, char Ticket[])
{
	LNODE *TempPtr;
    TempPtr = *LLH;

    if (TempPtr != NULL)                         //If linked list is not empty
    {
		strcpy(Ticket, TempPtr->Ticket);		 // Copy the ticket from the node into Ticket
		free(*LLH);								 // Free the memory  pointed to by LLH
		*LLH = (TempPtr)->next_ptr;              // Reset the head to the next link
	}
}
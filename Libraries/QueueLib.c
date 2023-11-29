/* QueueLib */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "QueueLib.h"

void enQueue(char CustomerName[], QNODE **QueueHead, QNODE **QueueTail)
{
    QNODE *NewNode = malloc(sizeof(QNODE));
	NewNode->name = malloc(strlen(CustomerName) * sizeof(char));
    strcpy(NewNode->name, CustomerName);
    NewNode->next_ptr = NULL;
	if (*QueueHead == NULL)
	{
		*QueueHead = *QueueTail = NewNode;
	}
	else
	{
		(*QueueTail)->next_ptr = NewNode;
		*QueueTail = NewNode;
	}
}
 
void deQueue(QNODE **QueueHead)
{
	QNODE *TempPtr = (*QueueHead)->next_ptr;
    if (*QueueHead != NULL)
	{
		free(*QueueHead);
		*QueueHead = TempPtr;
	}
}
 
void DisplayQueue(QNODE *QueueHead)
{
	QNODE *TempPtr = QueueHead;
	while (TempPtr != NULL)
	{
		printf("%s\n", TempPtr->name);
		TempPtr =  TempPtr->next_ptr;
	}
	return;
} 

#ifndef _QUEUE_LIB_H
#define _QUEUE_LIB_H

typedef struct QNODE
{
    char *name;
    struct QNODE *next_ptr;
} 
QNODE;

void enQueue(char [], QNODE **, QNODE **);
void deQueue(QNODE **);
void DisplayQueue(QNODE *);

#endif
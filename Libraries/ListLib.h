#ifndef _LIST_LIB_H
#define _LIST_LIB_H

typedef struct LNODE
{
    char Ticket[4];
    struct LNODE *next_ptr;
} 
LNODE;

void InsertNode(LNODE **, char[]);
void ReturnAndFreeLinkedListNode(LNODE **, char []);

#endif

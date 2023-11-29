#ifndef _BST_LIB_H
#define _BST_LIB_H

typedef struct BNODE
{
    char *MovieTheaterName;
    char ZipCode[6];
    char *FileName;
    char Dimensions[6];	
    struct BNODE *left;
    struct BNODE *right;
} 
BNODE;
void AddBSTNode(BNODE **, char [], char [], char [], char []);
void InOrder(BNODE *);
BNODE *SearchForBNODE(BNODE *, char []);

#endif

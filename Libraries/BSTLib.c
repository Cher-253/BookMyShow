/* BSTLib */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BSTLib.h"

void AddBSTNode(BNODE **BSTnode, char MTN[], char ZC[], char FN[], char DIM[])
{
    if (*BSTnode == NULL)
    {
        *BSTnode = malloc(sizeof(BNODE));
		(*BSTnode)->left = (*BSTnode)->right = NULL;
		(*BSTnode)->MovieTheaterName = malloc(strlen(MTN) * sizeof(char) + 1);
        strcpy((*BSTnode)->MovieTheaterName, MTN);
        strcpy((*BSTnode)->ZipCode, ZC);
		(*BSTnode)->FileName = malloc(strlen(FN) * sizeof(char) + 1);
        strcpy((*BSTnode)->FileName, FN);
        strcpy((*BSTnode)->Dimensions, DIM);
    }
    else
    {
        if (strcmp(ZC, (*BSTnode)->ZipCode) < 0)
			AddBSTNode(&(*BSTnode)->left, MTN, ZC, FN, DIM);
        else if(strcmp(ZC, (*BSTnode)->ZipCode) > 0)
            AddBSTNode(&(*BSTnode)->right, MTN, ZC, FN, DIM);
		else
            printf(" Duplicate Element !! Not Allowed !!!");
    }
}

void InOrder(BNODE *bnode)
{
    if(bnode != NULL)
    {
		InOrder(bnode->left);
        printf("%-40s %5s\n", bnode->MovieTheaterName, bnode->ZipCode);
		InOrder(bnode->right);
    }
}

BNODE *SearchForBNODE(BNODE *BSTnode, char zip[])
{
	if (BSTnode == NULL || strcmp(BSTnode->ZipCode, zip) == 0)
	{
		return BSTnode;
	}
	if (strcmp(zip, BSTnode->ZipCode) < 0)
		return SearchForBNODE(BSTnode->left, zip);	
    else if (strcmp(zip, BSTnode->ZipCode) > 0)
    	return SearchForBNODE(BSTnode->right, zip);
}
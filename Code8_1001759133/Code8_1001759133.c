#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MovieTheaterLib.h"
#include "QueueLib.h"
#include "BSTLib.h"
#include "ListLib.h"
#include "StackLib.h"

void PrintReceipts(SNODE **StackTop)
{
	char TempTicket[4];
	if(StackTop==NULL || &StackTop==NULL)
	{
		printf("No receipts\n");
	}
	else
	{
		while(*StackTop!=NULL)
		{
			printf("Receipt #%d\n\n\t%s\n\n",(*StackTop)->ReceiptNumber,(*StackTop)->MovieTheaterName);
			LNODE **TicketListtemp = &(*StackTop)->TicketList;
			while (*TicketListtemp!=NULL)
			{
				ReturnAndFreeLinkedListNode(TicketListtemp,TempTicket);
				printf("\t%s",TempTicket);
			}
			printf("\n") ;
			pop(StackTop);
		}		
	}	
}

BNODE *PickAndDisplayTheater(BNODE *BSTRoot, char MovieTheaterMap[][MAXCOLS], int *MapRow, int *MapCol)
{
	BNODE *MyTheater = NULL;
	char zip[6] = {};
	char MyDims[6] = {};
	int row=0,col=0;
	
	printf("\n\nPick a theater by entering the zipcode\n\n");
	InOrder(MyTheater);
	printf("Enter zip ");
	scanf("%d",zip);
	printf("\n");
	BNODE *TempBSTNode=SearchForBNODE(MyTheater,zip);
	if(TempBSTNode == NULL)
	{
		printf("Theater not found\n");
	}
	else
	{   
		row=atoi(strtok(TempBSTNode->Dimensions,"x"));
		col = atoi(strtok(NULL,"\0"));
	}
}	

void ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT)
{
	char CustomerName[30];
	if(QueueFile==NULL)
	{
		printf("File did not open , so program had to be terminated\n");
		exit(0);
	}
	else
	{
		while(fgets(CustomerName,30,QueueFile)!=NULL)
		{
			enQueue(CustomerName,QH,QT);
		}
	}
	
}

void ReadFileIntoBST(FILE *BSTFile, BNODE **BSTnode)
{
	if(BSTFile==NULL)
	{
		printf("File did not open , so program had to be terminated\n");
		exit(0);
	}
	else
	{
		char tempLine[100];
		int i=0,j=0;
		int L1,L2,L3,L4 =0;
		char *token = NULL;
		while(fgets(tempLine,100,BSTFile)!=NULL)
		{
			tempLine[strlen(tempLine)-1]='\0';
			char *tempToken;
			tempToken=strtok(tempLine,"|");
			L1 = strlen(tempToken);
			char MTN[L1];
			strcpy(MTN,tempToken);
			tempToken = strtok(NULL ,"|");
			char ZC[6];
			strcpy(ZC,tempToken);
			tempToken = strtok(NULL ,"|");
			L2 =strlen(tempToken);
			char FN[L2];
			strcpy(FN,tempToken);
			tempToken = strtok(NULL ,"\0");
			char DIM[6];
			strcpy(DIM,tempToken);
			AddBSTNode(BSTnode, MTN, ZC, FN, DIM);
		}
	}	
}

void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
	int i = 0; 
	while (argv[++i] != NULL)
	{
		if (!strncmp(argv[i], ParamName, strlen(ParamName)))
		{
			strcpy(ParamValue, strchr(argv[i], '=') + 1);
		}
	}
}

int PrintMenu(LNODE **TicketLinkedListHead,char Ticket[5])
{
	int choice = 0;
	printf("\n\n1.	Sell tickets to next customer\n\n");
	printf("2.	See who's in line\n\n");
	printf("3.	See the seat map for a given theater\n\n");
	printf("4.	Print today's receipts\n\n");
	printf("Choice : ");
	scanf("%d", &choice);
	if(choice == 3)
	{
		ReturnAndFreeLinkedListNode(TicketLinkedListHead,Ticket);
	}
	while (choice < 1 || choice > 4)
	{
		printf("Invalid choice.  Please reenter. ");
		scanf("%d", &choice);
	}
	return choice;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	FILE *queueFile = NULL;
	FILE *zipFile = NULL;
	char arg_value[20];
	char queuefilename[20];
	char zipfilename[20];
	int ReceiptNumber = 0;
	int choice = 0;
	int SeatNumber;
	char Row;
	char Ticket[5];
	int ArrayRow, ArrayCol;
	int MapRow, MapCol;
	char MovieTheaterMap[MAXROWS][MAXCOLS] = {};
	LNODE *TicketLinkedListHead = NULL;
	QNODE *QueueHead = NULL;
	QNODE *QueueTail = NULL;
	BNODE *BSTRoot = NULL;
	BNODE *MyTheater = NULL;
	SNODE *StackTop = NULL;
	int NumberOfTickets = 0;
	char SeatMap[26][20];

	if (argc != 4)
	{
		printf("%s QUEUE=xxxxxx ZIPFILE=xxxxx RECEIPTNUMBER=xxxxx\n", argv[0]);
		exit(0);
	}
	get_command_line_parameter(argv, "QUEUE=", queuefilename);
	get_command_line_parameter(argv, "ZIPFILE=", zipfilename);
	get_command_line_parameter(argv, "RECEIPTNUMBER=", arg_value);
	ReceiptNumber = atoi(arg_value);
    queueFile = fopen(queuefilename,"r");
    zipFile = fopen(zipfilename,"r");
	ReadFileIntoQueue(queueFile, &QueueHead, &QueueTail);
	ReadFileIntoBST(zipFile, &BSTRoot);
	
	while (QueueHead != NULL)
	{
		choice = PrintMenu(&TicketLinkedListHead,Ticket);
		switch (choice)
		{
			case 1 :
				printf("\n\nHello %s\n", QueueHead->name);				
				MyTheater = PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				if (MyTheater != NULL)
				{
					printf("\n\nHow many movie tickets do you want to buy? ");
					scanf("%d", &NumberOfTickets);
					for (i = 0; i < NumberOfTickets; i++)
					{
						do
						{
							printf("\nPick a seat (Row Seat) ");
							scanf(" %c%d", &Row, &SeatNumber);
							Row = toupper(Row);
							ArrayRow = (int)Row - 65;
							ArrayCol = SeatNumber - 1;
						
							if ((ArrayRow < 0 || ArrayRow >= MapRow) ||
								(ArrayCol < 0 || ArrayCol >= MapCol))
							{
								printf("\nThat is not a valid seat.  Please choose again\n\n");
							}		
						}
						while ((ArrayRow < 0 || ArrayRow >= MapRow) ||
							   (ArrayCol < 0 || ArrayCol >= MapCol));
						
						if (MovieTheaterMap[ArrayRow][ArrayCol] == 'O')
						{	
							MovieTheaterMap[ArrayRow][ArrayCol] = 'X';
							sprintf(Ticket, "%c%d", Row, SeatNumber); 
							InsertNode(&TicketLinkedListHead, Ticket);
						}
						else
						{
							printf("\nSeat %c%d is not available.\n\n", Row, SeatNumber);
							i--;
						}
						PrintSeatMap(MovieTheaterMap, MapRow, MapCol);
					}
					
					WriteSeatMap(MyTheater, MovieTheaterMap, MapRow, MapCol);
					push(&StackTop, TicketLinkedListHead, ReceiptNumber, MyTheater->MovieTheaterName);
					TicketLinkedListHead = NULL;
					ReceiptNumber++;
					printf("\nThank you %s - enjoy your movie!\n", QueueHead->name);
					deQueue(&QueueHead);
				}
				break;
			case 2 : 
				printf("\n\nCustomer Queue\n\n");
				DisplayQueue(QueueHead);
				printf("\n\n");
				break;
			case 3 :
				PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				break;
			case 4 : 
				PrintReceipts(&StackTop);
				break;
			default :
				printf("Bad menu choice");
		}
	}
	printf("Good job - you sold tickets to all of the customers in line.\n");
	PrintReceipts(&StackTop);
	return 0;
}

## Movie Theater Ticketing System  

This C program implements a movie theater ticketing system using various data structures such as queues, stacks, and binary search trees. It provides functionality to manage customer queues, sell tickets, print seat maps, and generate receipts.   

Code8_1.c:  
Main program that orchestrates the movie ticketing system.  
Implements user interactions, ticket selling, and receipt generation.  

BSTLib.c:  
Binary Search Tree (BST) library with functions to add nodes, perform in-order traversal, and search for nodes.    

ListLib.c:  
Linked list library for managing a list of tickets.  
Includes functions for inserting nodes and returning/freed linked list nodes.  

MovieTheaterLib.c:  
Library for movie theater-related functions.  
Includes functions to print seat maps, read and write theater files.  

QueueLib.c:  
Queue library for managing customer queues.  
Functions for enqueue, dequeue, and display the queue.  

StackLib.c:  
Stack library for managing receipts.  
Functions for pushing and popping stack nodes.  

Compilation:  
The makefile contains rules for compiling the source files into an executable named Code8_1.e.  

The program takes command line parameters:  
QUEUE=xxxxxx: File containing customer names.  
ZIPFILE=xxxxx: File containing theater information.  

Functionality:  
--> Customers are enqueued based on a file containing their names.  
--> Theater information is read from a file and stored in a Binary Search Tree.   
--> Customers are prompted to choose a theater based on their zip code.  
--> Tickets are sold, and the seat map is updated.  
--> Receipts are generated and stored in a stack.  
--> Seat maps for theaters are displayed.  
--> Receipts are printed, showing receipt numbers, theater names, and sold seats.  
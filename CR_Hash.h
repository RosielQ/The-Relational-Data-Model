#ifndef _CR_Hash_h_
#define _CR_Hash_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
typedef LinkedList CR_HashTable[1013];

typedef struct CR{
    char Course[6];
    char Room[100];
} *CR;

/*
given course and its room, return the CR
*/
extern CR new_CR(char* course, char* room);

/*
free the given CP 
*/
extern void free_CR(CR cr);

/*
free the given CP_HashTable (and free the data in each linkedlist as well)
*/
extern void free_CR_HashTable(CR_HashTable crTable);

/*
check if the two given CRs are the same
*/
extern bool check_SameCR(CR cr1, CR cr2);

/*
convert the course number into hash key
*/
extern int hashCourseRoom(CR cr);

/* 
Look up for the set of tuples in the table that match the specification cr (using primary index)
accepts: (CourseName, *) (CourseName, Room)
*/
extern LinkedList CR_lookup(CR cr, CR_HashTable table);

/*
Insert CR cr into the hashtable: assume that the two attributes are specified
*/
extern void CR_insert(CR cr, CR_HashTable table);

/*
delete CR cr into the hashtable: assume that the courseName is specifiec
*/
extern void CR_delete(CR cr, CR_HashTable table);

/*
Print CR's bucket
*/
extern void print_CRBuket(LinkedList crbuket);

/*
Print the CRTable
*/
extern void print_CRTable(CR_HashTable table);

#endif
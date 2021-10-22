#ifndef _CP_Hash_h_
#define _CP_Hash_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
typedef LinkedList CP_HashTable[1013];

typedef struct CP{
    char Course[6];
    char Pre[6];
} *CP;
/*
given course and its prerequisite, return the CP
*/
extern CP new_CP(char* course, char* pre);

/*
free the given CP 
*/
extern void free_CP(CP cp);

/*
free the given CP_HashTable (and free the data in each linkedlist as well)
*/
extern void free_CP_HashTable(CP_HashTable cpTable);

/*
check if the two given CPs are the same
*/
extern bool check_SameCP(CP cp1, CP cp2);

/*
convert the course number into hash key
*/
extern int hashCourse(CP cp);

/* 
Look up for the set of tuples in the table that match the specification cp (using primary index)
accepts: (CourseName, *) (CourseName, Pre)
*/
extern LinkedList CP_lookup(CP cp, CP_HashTable table);

/*
Insert CP cp into the hashtable: assume that the two attributes are specified
*/
extern void CP_insert(CP cp, CP_HashTable table);

/*
delete CP cp into the hashtable: assume that the courseName is specifiec
*/
extern void CP_delete(CP cp, CP_HashTable table);

/*
Print Cp's buckets
*/
extern void print_CPBuket(LinkedList cpbuket);

/*
Print the CPTable
*/
extern void print_CPTable(CP_HashTable table);

#endif
//
//  CDH.h
//  Project4
//
//  Created by 魏芊芊 on 4/17/21.
//

#ifndef CDH_h
#define CDH_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*--------------------Linked List Part--------------------*/


typedef struct NodeCDH* NodeCDH;

typedef struct LinkedListCDH* LinkedListCDH;

LinkedListCDH new_LinkedList_CDH();

NodeCDH new_Node_CDH(char* course, char* day, char* hour);

void free_NodeCDH(NodeCDH node);

void LinkedList_add_node_at_end_CDH(LinkedListCDH this, char* course, char* day, char* hour);

void LinkedList_delete_node_given_course_CDH(LinkedListCDH this, char* course);

void LinkedList_delete_node_CDH(LinkedListCDH this, char* course, char* day, char* hour);

/*--------------------hash table part--------------------*/

int convert_course_to_int_CDH(char* course);

void new_HashArray_CDH();

int hashcode_CDH(int key);

void insert_CDH(char* course, char* day, char* hour);

void delete_CDH(char* course, char* day, char* hour);

LinkedListCDH lookup_CDH(char* course, char* day, char* hour);

void print_relation_CDH();

void print_linkedList_CDH(LinkedListCDH list);

#endif /* CDH_h */

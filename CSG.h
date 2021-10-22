//
//  CSG.h
//  Project4
//
//  Created by 魏芊芊 on 4/17/21.
//

#ifndef CSG_h
#define CSG_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*--------------------Linked List Part--------------------*/


typedef struct NodeCSG* NodeCSG;

typedef struct LinkedListCSG* LinkedListCSG;

LinkedListCSG new_LinkedList_CSG();

NodeCSG new_Node_CSG(char* course, int id, char* grade);

void free_NodeCSG(NodeCSG node);

void LinkedList_add_node_at_end_CSG(LinkedListCSG this, char* course, int id, char* grade);

bool LinkedList_contains_id_CSG(const LinkedListCSG this, int id);

void LinkedList_delete_node_given_id_CSG(LinkedListCSG this, int id);



/*--------------------hash table part--------------------*/

void new_HashArray_CSG();

int hashcode_CSG(int key);

void insert_CSG(char* course, int id, char* grade);

void delete_CSG(char* course, int id, char* grade);

LinkedListCSG lookup_CSG(char* course, int id, char* grade);

void print_relation_CSG();

void print_linkedList_CSG(LinkedListCSG list);

#endif /* CSG_h */

//
//  hashTable.h
//  project3
//
//  Created by 魏芊芊 on 4/14/21.
//

#ifndef SNAP_h
#define SNAP_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*--------------------Linked List Part--------------------*/

int totalNodeSNAP;
int arraySizeSNAP;

typedef struct NodeSNAP* NodeSNAP;

typedef struct LinkedListSNAP* linkedListSNAP;


linkedListSNAP new_LinkedList_SNAP();

NodeSNAP new_Node_SNAP(int id, char* name, char* adrs, char* phone);

void free_NodeSNAP(NodeSNAP node);

void LinkedList_add_node_at_end_SNAP(linkedListSNAP this, int id, char* name, char* adrs, char* phone);

void LinkedList_delete_node_given_id_SNAP(linkedListSNAP this, int id);

/*--------------------hash table part--------------------*/

void new_HashArray_SNAP();

int hashcode_SNAP(int key);

void insert_SNAP(int id, char* name, char* adrs, char* phone);

void delete_SNAP(int id, char* name, char* adrs, char* phone);

linkedListSNAP lookup_SNAP(int id, char* name, char* adrs, char* phone);

void print_relation_SNAP();

void print_linkedList(linkedListSNAP list);

linkedListSNAP lookup_name_SNAP(char* name);

linkedListSNAP* return_HashArraySNAP()
#endif /* SNAP_h */

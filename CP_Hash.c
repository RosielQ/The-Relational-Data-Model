#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "CP_Hash.h"

int CP_tablesize = 1013;    //chose a 1000+ prime # as the table size
//typedef LinkedList CP_HashTable[1013];
CP_HashTable CP_table[1013];
/*struct CP{
    char Course[6];
    char Pre[6];
};*/

/*
given course and its prerequisite, return the CP
*/
CP new_CP(char* course, char* pre){
    CP newCP = (CP)malloc(sizeof(struct CP));
    //initiate course[]
    for(int i = 0; i < strlen(course); i ++){
        newCP -> Course[i] = course[i];
    }
    //initiate pre[]
    for(int i = 0; i < strlen(pre); i ++){
        newCP -> Pre[i] = pre[i];
    }
    return newCP;
}

/*
free the given CP 
*/
void free_CP(CP cp){
    free(cp);
}

/*
free the given CP_HashTable (and free the data in each linkedlist as well)
*/
void free_CP_HashTable(CP_HashTable cpTable){
    for(int i = 0; i < 1013; i++){
        if(cpTable[i] != NULL){
            LinkedList_free(cpTable[i], 1); //1:also free the data
        }
    }
}

/*
check if the two given CPs are the same
*/
bool check_SameCP(CP cp1, CP cp2){
    //check the coursename:
    if(strcmp(cp1 -> Course, cp2 -> Course) != 0){
        return false;
    }//else if either one of their pre equals "*" return true
    else if(strcmp(cp1 -> Course, cp2 -> Course) == 0 && (strcmp(cp1 -> Pre, "*") == 0 || strcmp(cp2 -> Pre, "*") == 0)){
        return true;
    }
    else{
        if(strcmp(cp1 -> Pre, cp2 -> Pre) != 0){
            return false;
        }
        return true;
    }
    //return true;
}

/*
convert the course number into hash key
*/
int hashCoursePre(CP cp){
    //use the course number mod a large prime number as the hash key
    //since we assume that course number only has three digits, the prime # has to be > 1000
    int courseNum = 0;
    int hundred = 0;
    int ten = 0;
    int ones = 0;
    int len = strlen(cp -> Course);
    ones = (int)(cp -> Course[len - 1]) - 48;
    ten = ((int)(cp -> Course[len - 2]) - 48) * 10;
    hundred = ((int)(cp -> Course[len - 3]) - 48) * 100;
    courseNum = ones + ten + hundred;   //convert the coursenumber to int type
    int hashkey = courseNum % CP_tablesize; //CP_tablesize = 1013
    return hashkey;
}

/* 
Look up for the set of tuples in the table that match the specification cp (using primary index)
accepts: (CourseName, *) (CourseName, Pre)
*/
LinkedList CP_lookup(CP cp, CP_HashTable table){
    LinkedList cplist = new_LinkedList();
    //when cp->Course != "*" && cp->Pre != "*": find and store the data
    if(strcmp(cp -> Course, "*") != 0 && strcmp(cp -> Pre, "*") != 0){
        int hashkey = hashCoursePre(cp);
        if(table[hashkey] != NULL){
            LinkedListIterator iterator = LinkedList_iterator(table[hashkey]);
            while(LinkedListIterator_hasNext(iterator)){
                CP current_cp = LinkedListIterator_next(iterator);
                if(check_SameCP(current_cp, cp) == true){
                    LinkedList_add_at_end(cplist, current_cp);
                    printf("Data found!\n");
                    free(iterator);
                    //return cplist;
                }
            }
        }
    }
    //when cp->Course != "*" && cp->Pre == "*": store all tuple that satisfy the requirment
    else if(strcmp(cp -> Course, "*") != 0 && strcmp(cp -> Pre, "*") == 0){
        int hashkey = hashCoursePre(cp);
        if(table[hashkey] != NULL){
            LinkedListIterator iterator = LinkedList_iterator(table[hashkey]);
            while(LinkedListIterator_hasNext(iterator)){
                CP current_cp = LinkedListIterator_next(iterator);
                if(strcmp(current_cp -> Course, cp -> Course) == 0){
                    LinkedList_add_at_end(cplist, current_cp);
                }
            }
            free(iterator);
        }
    }
    //when cp->Course == "*" && cp->Pre != "*" or both of them are "*": give a warning
    else{
        printf("please give a specific CourseName to look up!\n");
        return NULL;
    }
    if(cplist == NULL || LinkedList_isEmpty(cplist)){
        printf("Data Not Found!\n");
    }
    return cplist;
}

/*
Insert CP cp into the hashtable: assume that the two attributes are specified
*/
void CP_insert(CP cp, CP_HashTable table){
    int hashkey = hashCoursePre(cp);
    if(table[hashkey] == NULL){ //if there's no linked list in such busket
        table[hashkey] = new_LinkedList();
        LinkedList_add_at_end(table[hashkey], cp);
        return;
    }
    else{   //else: check if the same cp has already existed
        if(LinkedList_isEmpty(CP_lookup(cp, table))){
            LinkedList_add_at_end(table[hashkey], cp);
        }
    }
}

/*
delete CP cp into the hashtable: assume that the courseName is specifiec
*/
void CP_delete(CP cp, CP_HashTable table){
    int hashkey = hashCoursePre(cp);
    if(table[hashkey] != NULL){
        if(strcmp(cp -> Pre, "*") == 0){    //if pre is not specified
            LinkedListIterator iterator = LinkedList_iterator(table[hashkey]);
            while(LinkedListIterator_hasNext(iterator)){
                CP current_cp = LinkedListIterator_next(iterator);
                if (strcmp(current_cp -> Course, cp -> Course) == 0){
                    LinkedList_remove(table[hashkey], current_cp);
                }
            }
            free(iterator);
        }
        else{
            LinkedList_remove(table[hashkey], cp);
        }
    }
}

/*
Print Cp's buckets
*/
void print_CPBuket(LinkedList cpbuket){
    LinkedListIterator iterator = LinkedList_iterator(cpbuket);
	while (LinkedListIterator_hasNext(iterator)){
		CP current_cp = LinkedListIterator_next(iterator);
		printf("( %s , %s )\n", current_cp -> Course, current_cp -> Pre);
	}
	free(iterator);
}

/*
Print the CPTable
*/
void print_CPTable(CP_HashTable table){
    printf("( Course , Prerequisite )\n");
    for(int i = 0; i < CP_tablesize; i++){
        if(table[i] != NULL){
            print_CPBuket(table[i]);
        }
    }
}
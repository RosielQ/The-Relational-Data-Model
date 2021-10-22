#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "CR_Hash.h"

int CR_tablesize = 1013;    //chose a 1000+ prime # as the table size


/*
given course and its room, return the CR
*/
CR new_CR(char* course, char* room){
    CR newCR = (CR)malloc(sizeof(struct CR));
    //initiate course[]
    for(int i = 0; i < strlen(course); i ++){
        newCR -> Course[i] = course[i];
    }
    //initiate room[]
    for(int i = 0; i < strlen(room); i ++){
        newCR -> Room[i] = room[i];
    }
    return newCR;
}

/*
free the given CR 
*/
void free_CR(CR cr){
    free(cr);
}

/*
free the given CR_HashTable (and free the data in each linkedlist as well)
*/
void free_CR_HashTable(CR_HashTable crTable){
    for(int i = 0; i < 1013; i++){
        if(crTable[i] != NULL){
            LinkedList_free(crTable[i], 1); //1:also free the data
        }
    }
}

/*
check if the two given CRs are the same
*/
bool check_SameCR(CR cr1, CR cr2){
    //check the coursename:
    if(strcmp(cr1 -> Course, cr2 -> Course) != 0){
        return false;
    }//else if either one of their room equals "*" return true
    else if(strcmp(cr1 -> Course, cr2 -> Course) == 0 && (strcmp(cr1 -> Room, "*") == 0 || strcmp(cr2 -> Room, "*") == 0)){
        return true;
    }
    else{
        if(strcmp(cr1 -> Room, cr2 -> Room) != 0){
            return false;
        }
        return true;
    }
    //return true;
}

/*
convert the course number into hash key
*/
int hashCourseRoom(CR cr){
    //use the course number mod a large prime number as the hash key
    //since we assume that course number only has three digits, the prime # has to be > 1000
    int courseNum = 0;
    int hundred = 0;
    int ten = 0;
    int ones = 0;
    int len = strlen(cr -> Course);
    ones = (int)(cr -> Course[len - 1]) - 48;
    ten = ((int)(cr -> Course[len - 2]) - 48) * 10;
    hundred = ((int)(cr -> Course[len - 3]) - 48) * 100;
    courseNum = ones + ten + hundred;   //convert the coursenumber to int type
    int hashkey = courseNum % CR_tablesize; //CR_tablesize = 1013
    return hashkey;
}

/* 
Look up for the set of tuples in the table that match the specification cr (using primary index)
accepts: (CourseName, *) (CourseName, Room)
*/
LinkedList CR_lookup(CR cr, CR_HashTable table){
    LinkedList crlist = new_LinkedList();
    //when cr->Course != "*" && cr->Room != "*": find and store the data
    if(strcmp(cr -> Course, "*") != 0 && strcmp(cr -> Room, "*") != 0){
        int hashkey = hashCourseRoom(cr);
        if(table[hashkey] != NULL){
            LinkedListIterator iterator = LinkedList_iterator(table[hashkey]);
            while(LinkedListIterator_hasNext(iterator)){
                CR current_cr = LinkedListIterator_next(iterator);
                if(check_SameCR(current_cr, cr) == true){
                    LinkedList_add_at_end(crlist, current_cr);
                    printf("Data found!\n");
                    free(iterator);
                    //return cplist;
                }
            }
        }
    }
    //when cr->Course != "*" && cr->Room == "*": store all tuple that satisfy the requirment
    else if(strcmp(cr -> Course, "*") != 0 && strcmp(cr -> Room, "*") == 0){
        int hashkey = hashCourseRoom(cr);
        if(table[hashkey] != NULL){
            //printf("yes\n");
            LinkedListIterator iterator = LinkedList_iterator(table[hashkey]);
            //print_CRBuket(table[hashkey]);
            while(LinkedListIterator_hasNext(iterator)){
                CR current_cr = LinkedListIterator_next(iterator);
                if(strcmp(current_cr -> Course, cr -> Course) == 0){
                    LinkedList_add_at_end(crlist, current_cr);
                }
            }
            free(iterator);
        }
    }
    //when cr->Course == "*" && cr->Room != "*" or both of them are "*": give a warning
    else{
        printf("Please give a specific CourseName to look up!\n");
        return NULL;
    }
    if(crlist == NULL || LinkedList_isEmpty(crlist)){
        printf("Data Not Found!\n");
    }
    return crlist;
}

/*
Insert CR cr into the hashtable: assume that the two attributes are specified
*/
void CR_insert(CR cr, CR_HashTable table){
    int hashkey = hashCourseRoom(cr);
    if(table[hashkey] == NULL){ //if there's no linked list in such busket
        table[hashkey] = new_LinkedList();
        LinkedList_add_at_end(table[hashkey], cr);
        return;
    }
    else{   //else: check if the same cr has already existed
        if(LinkedList_isEmpty(CR_lookup(cr, table))){
            LinkedList_add_at_end(table[hashkey], cr);
        }
    }
}

/*
delete CR cr into the hashtable: assume that the courseName is specifiec
*/
void CR_delete(CR cr, CR_HashTable table){
    int hashkey = hashCourseRoom(cr);
    if(table[hashkey] != NULL){
        if(strcmp(cr -> Room, "*") == 0){    //if room is not specified
            LinkedListIterator iterator = LinkedList_iterator(table[hashkey]);
            while(LinkedListIterator_hasNext(iterator)){
                CR current_cr = LinkedListIterator_next(iterator);
                if (strcmp(current_cr -> Course, cr -> Course) == 0){
                    LinkedList_remove(table[hashkey], current_cr);
                }
            }
            free(iterator);
        }
        else{
            LinkedList_remove(table[hashkey], cr);
        }
    }
}

/*
Print Cr's bucket
*/
void print_CRBuket(LinkedList crbuket){
    LinkedListIterator iterator = LinkedList_iterator(crbuket);
	while (LinkedListIterator_hasNext(iterator)){
		CR current_cr = LinkedListIterator_next(iterator);
		printf("( %s , %s )\n", current_cr -> Course, current_cr -> Room);
	}
	free(iterator);
}

/*
Print the CRTable
*/
void print_CRTable(CR_HashTable table){
    printf("( Course , Room )\n");
    for(int i = 0; i < CR_tablesize; i++){
        if(table[i] != NULL){
            print_CRBuket(table[i]);
        }
    }
}
//
//  CDH.c
//  Project4
//
//  Created by 魏芊芊 on 4/17/21.
//

#include "CDH.h"

int totalNodeCDH = 0;
int arraySizeCDH = 100;
LinkedListCDH HashArrayCDH[100];


/*--------------------Linked List Part--------------------*/


struct NodeCDH{

    char* Course;//values
    char* Day;
    char* Hour;
    
    int Key;//key
   
    struct NodeCDH* next;//next node
    struct NodeCDH* prev;//previous node
};


struct LinkedListCDH{
    struct NodeCDH* first;
    struct NodeCDH* last;
};


LinkedListCDH new_LinkedList_CDH() {
    LinkedListCDH this = (LinkedListCDH)malloc(sizeof(struct LinkedListCDH));
    this->first =NULL;
    this->last = NULL;
    return this;
}

NodeCDH new_Node_CDH( char* course, char* day, char* hour) {
    NodeCDH node = (NodeCDH)malloc(sizeof(struct NodeCDH));
    
    node->Course = course;
    node->Day = day;
    node->Hour = hour;
    
    node->Key = convert_course_to_int_CDH(course);
    
    node->next = NULL;
    node->prev= NULL;
    
    return node;
}


void free_NodeCDH(NodeCDH node){
    if (node == NULL) {
        return;
    }
    
    if(node->Course != NULL)
        free(node->Course);
    if(node->Day != NULL)
        free(node->Day);
    if(node->Hour != NULL)
        free(node->Hour);
    if(node->next != NULL)
        free(node->next);
    if(node->prev != NULL)
        free(node->prev);
    
    free(node);
}


void LinkedList_add_node_at_end_CDH(LinkedListCDH this, char* course, char* day, char* hour){
    NodeCDH node = new_Node_CDH(course, day, hour);
    
    if(this->first == NULL){//list is empty
        this->first = node;
        this->last = node;
    }
    else{//list has first and last
        node->prev = this->last;
        this->last->next = node;
        this->last = node;
    }
}



void LinkedList_delete_node_given_course_CDH(LinkedListCDH this, char* course){
    for (NodeCDH node=this->first; node != NULL; node=node->next) {
        if (strcmp(node->Course, course) == 0) {
            if (node == this->first) {
                this->first = node->next;
            }
            if (node == this->last) {
                this->last = node->prev;
            }
            if (node->prev != NULL) {
                node->prev->next = node->next;
            }
            if (node->next != NULL) {
                node->next->prev = node->prev;
            }
            free(node);
        }
    }
}

void LinkedList_delete_node_CDH(LinkedListCDH this, char* course, char* day, char* hour){
    for (NodeCDH node=this->first; node != NULL; node=node->next) {
        if (strcmp(node->Course, course)==0) {
            if(strcmp(node->Day, day)==0){
                if(strcmp(node->Hour, hour)==0){
                    if (node == this->first) {
                        this->first = node->next;
                    }
                    if (node == this->last) {
                        this->last = node->prev;
                    }
                    if (node->prev != NULL) {
                        node->prev->next = node->next;
                    }
                    if (node->next != NULL) {
                        node->next->prev = node->prev;
                    }
                    free(node);
                }
            }
        }
    }
}



/*--------------------hash table part--------------------*/


//format of course name is always (two upper case letter) + (three digits)
//example: "CS201"
int convert_course_to_int_CDH(char* course){
    
    char intString[20] = "";
    
    for(int i=0;i<3;i++){
        if(course[i] == 'A')
            strcat(intString, "10");
        else if(course[i] == 'B')
            strcat(intString, "11");
        else if(course[i] == 'C')
            strcat(intString, "12");
        else if(course[i] == 'D')
            strcat(intString, "13");
        else if(course[i] == 'E')
            strcat(intString, "14");
        else if(course[i] == 'F')
            strcat(intString, "15");
        else if(course[i] == 'G')
            strcat(intString, "16");
        else if(course[i] == 'H')
            strcat(intString, "17");
        else if(course[i] == 'I')
            strcat(intString, "18");
        else if(course[i] == 'J')
            strcat(intString, "19");
        else if(course[i] == 'K')
            strcat(intString, "20");
        else if(course[i] == 'L')
            strcat(intString, "21");
        else if(course[i] == 'M')
            strcat(intString, "22");
        else if(course[i] == 'N')
            strcat(intString, "23");
        else if(course[i] == 'O')
            strcat(intString, "24");
        else if(course[i] == 'P')
            strcat(intString, "25");
        else if(course[i] == 'Q')
            strcat(intString, "26");
        else if(course[i] == 'R')
            strcat(intString, "27");
        else if(course[i] == 'S')
            strcat(intString, "28");
        else if(course[i] == 'T')
            strcat(intString, "29");
        else if(course[i] == 'U')
            strcat(intString, "30");
        else if(course[i] == 'V')
            strcat(intString, "31");
        else if(course[i] == 'W')
            strcat(intString, "32");
        else if(course[i] == 'X')
            strcat(intString, "33");
        else if(course[i] == 'Y')
            strcat(intString, "34");
        else
            strcat(intString, "35");
       
    }
    
    strcat(intString, &course[3]);

    return atoi(intString);

}


void new_HashArray_CDH(){
    for(int i=0;i<arraySizeCDH;i++)
        HashArrayCDH[i] = new_LinkedList_CDH();
}

int hashcode_CDH(int key){
    return (key % arraySizeCDH);
}


void insert_CDH(char* course, char* day, char* hour){
    if(lookup_CDH(course, day, hour)->first !=NULL){
        printf("Already exists. Nothing is inserted!\n");
    }
    else{
        int idx = hashcode_CDH(convert_course_to_int_CDH(course));
        LinkedListCDH currentList = HashArrayCDH[idx];
        LinkedList_add_node_at_end_CDH(currentList, course, day, hour);
        totalNodeCDH++;
        printf("Inserted!\n");
    }
}


/*
 this function support input format
    1) (course, day, hour)
    2) (course, *, *)
 */
void delete_CDH(char* course, char* day, char* hour){
    NodeCDH node = lookup_CDH(course, day, hour)->first;
    
    if(node != NULL){
        while(node != NULL){
            int idx = hashcode_CDH(convert_course_to_int_CDH(course));
            LinkedListCDH currentList = HashArrayCDH[idx];
            
            LinkedList_delete_node_CDH(currentList, node->Course, node->Day, node->Hour);
            node = node->next;
        }
    }
    else{
        printf("Not found. Nothing is deleted!\n");
    }
    
    
   
}


LinkedListCDH lookup_CDH(char* course, char* day, char* hour){
    
    int idx = hashcode_CDH(convert_course_to_int_CDH(course));
    LinkedListCDH currentList = HashArrayCDH[idx];
    NodeCDH currentNode = currentList->first;
    LinkedListCDH returnList = new_LinkedList_CDH();
    
    //currentList is empty
    if(currentNode == NULL){
        printf("Not found! currentList is empty\n");
    }
    else{//currentList contains something
        while(currentNode != NULL){
            if(strcmp(day, "*") == 0){//(course, *, *)
                LinkedList_add_node_at_end_CDH(returnList, course, currentNode->Day, currentNode->Hour);
            }
            else{//(course, day, hour)
                if(strcmp(currentNode->Course, course)==0){
                    if(strcmp(currentNode->Day, day)==0){
                        if(strcmp(currentNode->Hour, hour)==0){
                        LinkedList_add_node_at_end_CDH(returnList, course, day, hour);
                        }
                    }
                }
            }
        
        currentNode = currentNode->next;
        }
    }
//    printf("TEST!\n");
    if(returnList->first != NULL){
        printf("Found!\n");
        print_linkedList_CDH(returnList);
    }
    return returnList;
    
    
    
}


void print_relation_CDH(){
    printf("----------------------------------\n");
    printf ("| %10s%10s%10s |\n", "Course", "Day", "Hour");
    
    for(int i=0; i<arraySizeCDH; i++){
        LinkedListCDH currentList = HashArrayCDH[i];
        
        if(currentList->first != NULL){
            NodeCDH currentNode = currentList->first;
            
            while(currentNode != NULL){
                printf ("| %10s%10s%10s |\n", currentNode->Course, currentNode->Day, currentNode->Hour);
                currentNode = currentNode->next;
            }
        }
    }
    printf("----------------------------------\n");
}

void print_linkedList_CDH(LinkedListCDH list){
    for(NodeCDH node = list->first; node != NULL; node = node->next){
        printf ("( %s, %s, %s )\n", node->Course, node->Day,node->Hour);
    }
}







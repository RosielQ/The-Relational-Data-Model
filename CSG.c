
#include "CSG.h"

int totalNodeCSG = 0;
int arraySizeCSG = 100;
LinkedListCSG HashArrayCSG[100];


/*--------------------Linked List Part--------------------*/


struct NodeCSG{
    
    int StudentId;//key
    
    char* Course;//values
    char* Grade;
    
    struct NodeCSG* next;//next node
    struct NodeCSG* prev;//previous node
};

struct LinkedListCSG{
    struct NodeCSG* first;
    struct NodeCSG* last;
};


LinkedListCSG new_LinkedList_CSG() {
    LinkedListCSG this = (LinkedListCSG)malloc(sizeof(struct LinkedListCSG));
    this->first =NULL;
    this->last = NULL;
    return this;
}


NodeCSG new_Node_CSG(char* course, int id, char* grade) {
    NodeCSG node = (NodeCSG)malloc(sizeof(struct NodeCSG));
    node->StudentId = id;
    node->Course = course;
    node->Grade = grade;
    
    node->next = NULL;
    node->prev= NULL;
    
    return node;
}


void free_NodeCSG(NodeCSG node){
    if (node == NULL) {
        return;
    }
    
    if(node->Course != NULL)
        free(node->Course);
    if(node->Grade != NULL)
        free(node->Grade);

    if(node->next != NULL)
        free(node->next);
    if(node->prev != NULL)
        free(node->prev);
    
    free(node);
}


void LinkedList_add_node_at_end_CSG(LinkedListCSG this, char* course, int id, char* grade) {
    
    NodeCSG node = new_Node_CSG(course, id, grade);
    
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


void LinkedList_delete_node_given_id_CSG(LinkedListCSG this, int id) {
    for (NodeCSG node=this->first; node != NULL; node=node->next) {
        if (node->StudentId == id) {
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
        }
    }
}


/*--------------------hash table part--------------------*/



void new_HashArray_CSG() {
    for(int i=0;i<arraySizeCSG;i++)
        HashArrayCSG[i] = new_LinkedList_CSG();
}


int hashcode_CSG(int key){
    return (key % arraySizeCSG);
}


void insert_CSG(char* course, int id, char* grade){
    
    if(lookup_CSG(course, id, grade)->first != NULL){
        printf("Already exists. Nothing is inserted!\n");
    }
    else{
        LinkedListCSG currentList = HashArrayCSG[hashcode_CSG(id)];
        LinkedList_add_node_at_end_CSG(currentList, course, id, grade);
        totalNodeCSG++;
    }
}


/*
this function support:
    1) (course, id, grade)
    2) (*, id, *)
*/
void delete_CSG(char* course, int id, char* grade){
    
    if(lookup_CSG(course, id, grade)->first != NULL){
        LinkedListCSG currentList = HashArrayCSG[hashcode_CSG(id)];
        LinkedList_delete_node_given_id_CSG(currentList, id);
    }
    else{
        printf("Not found. Nothing is deleted!\n");
    }
}


/*
 this function support: 1) (course, id, grade)
                        2) (*, id, *)
 */
LinkedListCSG lookup_CSG(char* course, int id, char* grade){
    
    LinkedListCSG currentList = HashArrayCSG[hashcode_CSG(id)];
    NodeCSG currentNode = currentList->first;
    LinkedListCSG returnList = new_LinkedList_CSG();
    
    
    //currentList is empty
    if(currentNode == NULL){
        printf("Not found! currentList is empty\n");
    }
    else{//currentList contains something
        while(currentNode != NULL){
            if(strcmp(course, "*") == 0){//(*, id, *)
                LinkedList_add_node_at_end_CSG(returnList, currentNode->Course, id, currentNode->Grade);
            }
            else{//(id, name, adrs, phone)
                if(strcmp(currentNode->Course, course)==0){
                    if(strcmp(currentNode->Grade, grade)==0){
                        LinkedList_add_node_at_end_CSG(returnList, course, id, grade);
                    }
                }
            }
        
        currentNode = currentNode->next;
        }
    }
//    printf("TEST!\n");
    if(returnList->first != NULL){
        printf("Found!\n");
        print_linkedList_CSG(returnList);
    }
    return returnList;
}
//                printf("TEST!\n");
//                printf("%s %s\n",currentNode->Course, course);
//                printf("%s %s\n",currentNode->Grade, grade);


void print_relation_CSG(){
    printf("--------------------------------------------\n");
    printf ("| %10s%15s%15s |\n", "Course", "StudentId", "Grade");
    
    for(int i=0; i<arraySizeCSG; i++){
        LinkedListCSG currentList = HashArrayCSG[i];
        
        if(currentList->first != NULL){
            NodeCSG currentNode = currentList->first;
            
            while(currentNode != NULL){
                printf ("| %10s%15d%15s |\n",
                        currentNode->Course,currentNode->StudentId,currentNode->Grade);
                currentNode = currentNode->next;
            }
        }
    }
    printf("--------------------------------------------\n");
}


void print_linkedList_CSG(LinkedListCSG list){
    for(NodeCSG node = list->first; node != NULL; node = node->next){
        printf ("( %s, %d, %s )\n", node->Course, node->StudentId,node->Grade);
    }
}


#include "SNAP.h"

int totalNodeSNAP = 0;
int arraySizeSNAP = 100;
linkedListSNAP HashArraySNAP[100];


/*--------------------Linked List Part--------------------*/




struct NodeSNAP{
    
    int StudentId;//key
    
    char* Name;//values
    char* Address;
    char* Phone;
    
    struct NodeSNAP* next;//next node
    struct NodeSNAP* prev;//previous node
};


struct LinkedListSNAP{
    struct NodeSNAP* first;
    struct NodeSNAP* last;
};


linkedListSNAP new_LinkedList_SNAP() {
    linkedListSNAP this = (linkedListSNAP)malloc(sizeof(struct LinkedListSNAP));
    this->first =NULL;
    this->last = NULL;
    return this;
}


NodeSNAP new_Node_SNAP(int id, char* name, char* adrs, char* phone) {
    NodeSNAP node = (NodeSNAP)malloc(sizeof(struct NodeSNAP));
    node->StudentId = id;
    node->Name = name;
    node->Address = adrs;
    node->Phone = phone;
    node->next = NULL;
    node->prev= NULL;
    
    return node;
}

//free the give node
void free_NodeSNAP(NodeSNAP node){
    if (node == NULL) {
        return;
    }
    
    if(node->Name != NULL)
        free(node->Name);
    if(node->Address != NULL)
        free(node->Address);
    if(node->Phone != NULL)
        free(node->Phone);
    if(node->next != NULL)
        free(node->next);
    if(node->prev != NULL)
        free(node->prev);
    
    free(node);
}



//add a new node at the end of the given linked list
void LinkedList_add_node_at_end_SNAP(linkedListSNAP this, int id, char* name, char* adrs, char* phone) {
    
    NodeSNAP node = new_Node_SNAP(id, name, adrs, phone);
    
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


//remove the node with given id if it is there
void LinkedList_delete_node_given_id_SNAP(linkedListSNAP this, int id) {
    for (NodeSNAP node=this->first; node != NULL; node=node->next) {
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


void new_HashArray_SNAP() {
    for(int i=0;i<arraySizeSNAP;i++)
        HashArraySNAP[i] = new_LinkedList_SNAP();
}


int hashcode_SNAP(int key){
    return (key % arraySizeSNAP);
}


void insert_SNAP(int id, char* name, char* adrs, char* phone){
    
    if(lookup_SNAP(id, name, adrs, phone) != NULL){
        printf("Already exists. Nothing is inserted!\n");
    }
    else{
        linkedListSNAP currentList = HashArraySNAP[hashcode_SNAP(id)];
        LinkedList_add_node_at_end_SNAP(currentList, id, name, adrs, phone);
        totalNodeSNAP++;
        
    }
}

/*
this function support:
    1) (id, name, address, phone)
    2) (id, *, *, *)
*/
void delete_SNAP(int id, char* name, char* adrs, char* phone){
    
    if(lookup_SNAP(id, name, adrs, phone) != NULL){
        linkedListSNAP currentList = HashArraySNAP[hashcode_SNAP(id)];
        LinkedList_delete_node_given_id_SNAP(currentList, id);
    }
    else{
        printf("Not found. Nothing is deleted!\n");
    }
}



/*
 this function support: (id, name, address, phone)
                        (id, *, *, *)
 */
linkedListSNAP lookup_SNAP(int id, char* name, char* adrs, char* phone){
    
    linkedListSNAP currentList = HashArraySNAP[hashcode_SNAP(id)];
    NodeSNAP currentNode = currentList->first;
    linkedListSNAP returnList = NULL;
    
    //currentList is empty
    if(currentNode == NULL){
        printf("Not found! currentList is empty\n");
    }
    else{//currentList contains something
        while(currentNode != NULL && currentNode->StudentId != id){
            currentNode = currentNode->next;
        }
        
        if(currentNode == NULL){//id not found
            printf("Not found! no id\n");
        }
        else{// id found

            if(strcmp(name, "*") == 0){//(id, *, *, *)
                printf("Found!\n");
                printf("( %d, %s, %s, %s )\n",id, currentNode->Name, currentNode->Address, currentNode->Phone);
                returnList = new_LinkedList_SNAP();
                LinkedList_add_node_at_end_SNAP(returnList, id, currentNode->Name, currentNode->Address, currentNode->Phone);
            }
            else{//(id, name, adrs, phone)
                if(strcmp(currentNode->Name, name)==0){
                    
                    if(strcmp(currentNode->Address, adrs)==0){
                        
                        if(strcmp(currentNode->Phone, phone)==0){
            
                            returnList = new_LinkedList_SNAP();
                            LinkedList_add_node_at_end_SNAP(returnList, id, name, adrs, phone);
                            
                            printf("Found!\n");
                            printf("( %d, %s, %s, %s )\n",id, name, adrs, phone);
                            
                        }
                    }
                }
                else{//wrong nap
                    printf("Not found! id found, Wrong nap\n");
                }
            }
        }
    }
    return returnList;
}


void print_relation_SNAP(){
    printf("----------------------------------------------------------------\n");
    printf ("| %10s%15s%20s%15s |\n", "StudentId", "Name", "Address", "Phone");
    
    for(int i=0; i<arraySizeSNAP; i++){
        linkedListSNAP currentList = HashArraySNAP[i];
        
        if(currentList->first != NULL){
            NodeSNAP currentNode = currentList->first;
            
            while(currentNode != NULL){
                printf ("| %10d%15s%20s%15s |\n",
                        currentNode->StudentId,currentNode->Name,currentNode->Address,currentNode->Phone);
                currentNode = currentNode->next;
            }
        }
    }
    printf("----------------------------------------------------------------\n");
}

void print_linkedList(linkedListSNAP list){
    for(NodeSNAP node = list->first; node != NULL; node = node->next){
        printf ("( %d, %s, %s, %s )\n", node->StudentId,node->Name,node->Address,node->Phone);
    }
}

linkedListSNAP lookup_name_SNAP(char* name){
    
    linkedListSNAP returnList = new_LinkedList_SNAP();

    for(int i=0; i<arraySizeSNAP;i++){
        for(NodeSNAP node = HashArraySNAP[i]->first; node != NULL; node = node->next){
            if(strcmp(node->Name, name) == 0){
                LinkedList_add_node_at_end_SNAP(returnList, node->StudentId, node->Name, node->Address, node->Phone);
            }
        }
        
    }
    print_linkedList(returnList);
    return returnList;
}

linkedListSNAP* return_HashArraySNAP(){
    return HashArraySNAP;
}


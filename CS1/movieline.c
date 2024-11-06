<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAXLEN 50

// Tyler Bazemore
// COP3503C Assignment P1
// 8/30/2023




typedef struct customer{
    char* name;
    char firstLetter;
    int tix;
    int timeEnter;
    int queue;
}customer;
typedef struct node{
    customer* cus;
    struct node* next;

}node;
typedef struct queue{
    node* front;
    node* back;
    int size;
}queue;

customer* createCustomer(char* this_name, int this_tix, int this_timeEnter);
//void dequeue(queue* this_queue, node* this_node);
void enqueue(queue* this_queue, node* this_node);
node* createNode(customer* curCustomer);
queue* createQueue();
int smallestQ(queue* q);
void findQueue(queue ** allQs, customer* new_customer);
void freeCus(customer* this_customer);
void freeNode(node* this_node);
int countOccur(node* head, int search_for);

int main(){
    int customers = 0, booths = 0, time = 0, this_tix = 0, this_timeEnter = 0;
    

    scanf("%d %d", &customers, &booths);
    queue* que = createQueue();
    for (int i = 0;i< customers; i++){
        char* this_name = calloc(MAXLEN+1, sizeof(char));
        scanf("%s %d %d", this_name, &this_tix, &this_timeEnter);
        customer* this_customer = createCustomer(this_name, this_tix, this_timeEnter);
        
        node* this_node = createNode(this_customer);
        if ((this_customer->firstLetter - 'A') % 13 == 0){
            int smallest = 13;
            for (int k = 1; k < 13; k++){
                if (countOccur(this_node, k)!= 0 && smallest > countOccur(this_node, k)){
                    printf("1");
                    smallest = countOccur(this_node, k);
                }
            }
            this_customer-> queue =  smallest;
        }
        else{
            this_customer->queue = (this_customer->firstLetter - 'A') % 13;
        }
        enqueue(que, this_node);
    }
    node* head = que->front;
    queue* sortedQ = createQueue();
    node* cur = que->front; 
    node* nex = cur->next;
    
    head = que->front;
    printf("\n\n");
    for (int z = 0; z < customers; z++){
        printf(" %d %s %d ", head->cus->timeEnter, head->cus->name, head->cus->queue);
        head = head->next;
    }
    return 0;
}

queue* createQueue(){
    queue* q = malloc(sizeof(queue));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}
customer* createCustomer(char* this_name, int this_tix, int this_timeEnter){
    char* name = calloc(MAXLEN+1, sizeof(char));
    name = this_name;
    customer* nodeTmp = malloc(sizeof(customer));
    nodeTmp -> name = calloc(MAXLEN+1, sizeof(char));
    nodeTmp -> name = name;
    nodeTmp -> tix = this_tix;
    nodeTmp ->firstLetter = name[0];
    nodeTmp -> timeEnter = this_timeEnter;
    nodeTmp -> queue = 0;
    return nodeTmp;
}
node* createNode(customer* curCustomer){
    customer * new_customer = curCustomer; 
    node* curNode = malloc(sizeof(node));
    curNode -> cus = new_customer;
    curNode -> next = NULL;
    return curNode;
}
void enqueue(queue* this_queue, node* this_node){
    if (this_queue-> front == NULL){
        this_queue->front = this_node;
        // this_queue->back = this_node;
        this_queue-> size = 1;
    }
    else if (this_queue->size == 1){
        this_queue->back = this_node;
        this_queue->front->next = this_node;
        this_queue->size++;
    }
    else{
        this_queue->back->next = this_node;
        this_queue->back = this_node;
        this_queue->size++;
    }

}
int countOccur(node* head, int search_for){
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        if (current->cus->queue == search_for)
            count++;
        current = current->next;
    }
    return count;
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAXLEN 50

// Tyler Bazemore
// COP3503C Assignment P1
// 8/30/2023




typedef struct customer{
    char* name;
    char firstLetter;
    int tix;
    int timeEnter;
    int queue;
}customer;
typedef struct node{
    customer* cus;
    struct node* next;

}node;
typedef struct queue{
    node* front;
    node* back;
    int size;
}queue;

customer* createCustomer(char* this_name, int this_tix, int this_timeEnter);
//void dequeue(queue* this_queue, node* this_node);
void enqueue(queue* this_queue, node* this_node);
node* createNode(customer* curCustomer);
queue* createQueue();
int smallestQ(queue* q);
void findQueue(queue ** allQs, customer* new_customer);
void freeCus(customer* this_customer);
void freeNode(node* this_node);
int countOccur(node* head, int search_for);

int main(){
    int customers = 0, booths = 0, time = 0, this_tix = 0, this_timeEnter = 0;
    

    scanf("%d %d", &customers, &booths);
    queue* que = createQueue();
    for (int i = 0;i< customers; i++){
        char* this_name = calloc(MAXLEN+1, sizeof(char));
        scanf("%s %d %d", this_name, &this_tix, &this_timeEnter);
        customer* this_customer = createCustomer(this_name, this_tix, this_timeEnter);
        
        node* this_node = createNode(this_customer);
        if ((this_customer->firstLetter - 'A') % 13 == 0){
            int smallest = 13;
            for (int k = 1; k < 13; k++){
                if (countOccur(this_node, k)!= 0 && smallest > countOccur(this_node, k)){
                    printf("1");
                    smallest = countOccur(this_node, k);
                }
            }
            this_customer-> queue =  smallest;
        }
        else{
            this_customer->queue = (this_customer->firstLetter - 'A') % 13;
        }
        enqueue(que, this_node);
    }
    node* head = que->front;
    queue* sortedQ = createQueue();
    node* cur = que->front; 
    node* nex = cur->next;
    
    head = que->front;
    printf("\n\n");
    for (int z = 0; z < customers; z++){
        printf(" %d %s %d ", head->cus->timeEnter, head->cus->name, head->cus->queue);
        head = head->next;
    }
    return 0;
}

queue* createQueue(){
    queue* q = malloc(sizeof(queue));
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}
customer* createCustomer(char* this_name, int this_tix, int this_timeEnter){
    char* name = calloc(MAXLEN+1, sizeof(char));
    name = this_name;
    customer* nodeTmp = malloc(sizeof(customer));
    nodeTmp -> name = calloc(MAXLEN+1, sizeof(char));
    nodeTmp -> name = name;
    nodeTmp -> tix = this_tix;
    nodeTmp ->firstLetter = name[0];
    nodeTmp -> timeEnter = this_timeEnter;
    nodeTmp -> queue = 0;
    return nodeTmp;
}
node* createNode(customer* curCustomer){
    customer * new_customer = curCustomer; 
    node* curNode = malloc(sizeof(node));
    curNode -> cus = new_customer;
    curNode -> next = NULL;
    return curNode;
}
void enqueue(queue* this_queue, node* this_node){
    if (this_queue-> front == NULL){
        this_queue->front = this_node;
        // this_queue->back = this_node;
        this_queue-> size = 1;
    }
    else if (this_queue->size == 1){
        this_queue->back = this_node;
        this_queue->front->next = this_node;
        this_queue->size++;
    }
    else{
        this_queue->back->next = this_node;
        this_queue->back = this_node;
        this_queue->size++;
    }

}
int countOccur(node* head, int search_for){
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        if (current->cus->queue == search_for)
            count++;
        current = current->next;
    }
    return count;
>>>>>>> b756d6d (Updating repositroy using git)
}
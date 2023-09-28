#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXLEN 50

// Tyler Bazemore
// COP3503C Assignment P2
// 9/21/2023


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

int DEBUG = 1;

customer* createCustomer(char* this_name, int this_tix, int this_timeEnter);
queue* dequeue(queue* this_queue, node* this_node);
void enqueue(queue* this_queue, node* this_node);
node* createNode(customer* curCustomer);
queue* createQueue();
int smallestQ(queue** q);
void findQueue(queue ** allQs, customer* new_customer);
void freeCus(customer* this_customer);
void freeNode(node* this_node);
int totalCus(int qSizes[12], int star, int end);

int main(){
    int customers = 0, booths = 0, time = 0, this_tix = 0, this_timeEnter = 0;



    scanf("%d %d", &customers, &booths);
    queue** allQs = calloc(13, sizeof(queue*));
    for (int a = 0; a < 13;a++){
        //printf("a %d ",a);
        allQs[a] = createQueue();
    }
    // Enters in each customer to queue is allQs array of pointers.
    for (int i = 0; i<customers; i++){
        char* this_name = calloc(MAXLEN+1, sizeof(char));
        scanf("%s %d %d", this_name, &this_tix, &this_timeEnter);
        customer* new_customer = createCustomer(this_name, this_tix, this_timeEnter);

        for (int b = 0;b < 13;b++){
            node* new_node = createNode(new_customer);
            if ((new_customer->firstLetter - 'A') % 13 == b){
                if (b == 0){
                    int small = smallestQ(allQs);
                    enqueue(allQs[small], new_node);
                    new_node->cus->queue = small;
                }
                else{
                enqueue(allQs[b], new_node);
                new_node->cus->queue = b;
                }

            }
        }
    }
    // gets total # of queues used
    int totalQs = 0;
    for (int j = 0; j < 13;j++){
        if (allQs[j]->size <= 500000){
            totalQs++;
        }
    }
    int qNumbers[12] = {};
    int qSizes[12] = {};
    int count = 0;
    // gets sizes of every queue and puts them i array that corresponds to totalQs, mostly used to see how many total customers in a 
    // specific range
    for (int j = 0; j < 13;j++){
        if (allQs[j]->size <= 500000){
            qNumbers[count] = allQs[j]->front->cus->queue;
            qSizes[count] = allQs[j]->size;
            count++;
        }
    }
    count = 0;
    int remainingQs = 0;
    int y = 0;
    int start = 0;
    int end = 0;
    //adder is how many booths with queue value of booths
    // remain is how main with queue value of booths-1
    int adder = totalQs%booths;
    int remain = totalQs/booths;
    int boothC = remain;
    for (int j = 0; j < booths;j++){
        printf("Booth %d\n", j+1);
        // boothC acts as how many booths require the adder value to get the end queue value and how many need the remain end queue value added on
        if (boothC > 0){
            if (start == 0){
            end = start + adder + 1;
            }
            else{
               end = start; 
               end = end + adder + 1;
            }
            // need to find lowest and 2nd lowest as the 2nd lowest is when the lowest enter time leaves the queue
            node* low = allQs[qNumbers[start]]->front;
            // try to look over every customer as I will need to dequeue every customer eventually from each queue in the range
            int totalTime = 0;
            for (int l = 0; l < totalCus(qSizes, start, end); l++){
                
                //all queues->front are in order so the front is the lowest in that queue
                int h = start;
                if (DEBUG == 1) printf("%d\n", h);
                for (h = start; h < end; h++){
                    int search = qNumbers[h];
                    //if (DEBUG == 1) printf("%d\n", qNumbers[h]);
                    //if (DEBUG == 1) printf("%d\n", h);
                    if (low == NULL){
                        low = allQs[search]->front;
                    }
                    else if (allQs[search]->front == NULL){
                        ;
                    }
                    else if(low == allQs[search]->front){
                        ;
                    }
                    // segfaults here
                    else if (low->cus->timeEnter > allQs[search]->front->cus->timeEnter){

                        low = allQs[search]->front;
                    }
                }
                if (low->cus->timeEnter > totalTime){
                    totalTime = low->cus->timeEnter;
                    printf("%s from line %d checks out at time %d", low->cus->name, low->cus->queue, totalTime + (30 + (low->cus->tix * 5)));
                    printf("\n");
                }
                else{
                    printf("%s from line %d checks out at time %d", low->cus->name, low->cus->queue, totalTime + (30 + (low->cus->tix * 5)));
                    printf("\n");
                }

                totalTime = totalTime + (30 + (low->cus->tix * 5));
                // ^ format for how it needs to print out
                // dequeueing low and setting it equal to nextlow
                allQs[low->cus->queue] = dequeue(allQs[qNumbers[low->cus->queue]], low);
                for (int k = start; k < end;k++){
                    if (allQs[qNumbers[k]]->front != NULL){
                        low = allQs[qNumbers[k]]->front;
                    }
                }


                
            }
        }

        
        else if (remain > 0){
           if (start == 0){
            end = start + adder;
            }
            else{
               end = start; 
               end = end + adder;
            }
            // need to find lowest and 2nd lowest as the 2nd lowest is when the lowest enter time leaves the queue
            node* low = allQs[qNumbers[start]]->front;
            // try to look over every customer as I will need to dequeue every customer eventually from each queue in the range
            int totalTime = 0;
            for (int l = 0; l < totalCus(qSizes, start, end); l++){
                
                //all queues->front are in order so the front is the lowest in that queue
                int h = start;
                if (DEBUG == 1) printf("%d\n", h);
                for (h = start; h < end; h++){
                    int search = qNumbers[h];
                    //if (DEBUG == 1) printf("%d\n", qNumbers[h]);
                    //if (DEBUG == 1) printf("%d\n", h);
                    if (low == NULL){
                        low = allQs[search]->front;
                    }
                    else if (allQs[search]->front == NULL){
                        ;
                    }
                    else if(low == allQs[search]->front){
                        ;
                    }
                    // segfaults here
                    else if (low->cus->timeEnter > allQs[search]->front->cus->timeEnter){

                        low = allQs[search]->front;
                    }
                }
                if (low->cus->timeEnter > totalTime){
                    totalTime = low->cus->timeEnter;
                    printf("%s from line %d checks out at time %d", low->cus->name, low->cus->queue, totalTime + (30 + (low->cus->tix * 5)));
                    printf("\n");
                }
                else{
                    printf("%s from line %d checks out at time %d", low->cus->name, low->cus->queue, totalTime + (30 + (low->cus->tix * 5)));
                    printf("\n");
                }

                totalTime = totalTime + (30 + (low->cus->tix * 5));
                // ^ format for how it needs to print out
                // dequeueing low and setting it equal to nextlow
                allQs[low->cus->queue] = dequeue(allQs[qNumbers[low->cus->queue]], low);
                for (int k = start; k < end;k++){
                    if (allQs[qNumbers[k]]->front != NULL){
                        low = allQs[qNumbers[k]]->front;
                    }
                }


                
            }
        }
        start = end ;
        boothC--;
        // if the remain is > 0 which is how many do not use the adder variable to add to start do the exact same excepy all with the adder
        printf("\n");
        

    }


    return 0;
}
// find total customers in desired range
int totalCus(int qSizes[12], int star, int end){
    int i = 0;
    int total = 0;
    for ( i  = star; i < end; i++){
        total += qSizes[i];
    }
    return total;
}
// finds smallest q, only used in adder every customer to a queue
int smallestQ(queue** q){
    int Qsize = 500002;
    int smallestQ = 0;
    for (int i = 0; i < 13;i++){
        if (q[i]->size < Qsize){
            smallestQ = i;
            Qsize = q[i] -> size;
        }
        else{
            ;
        }
    }
    return smallestQ;
}
// creates a queue which makes up allQs array of pointers
queue* createQueue(){
    queue* q = malloc(sizeof(queue));
    q->front = NULL;
    q->back = NULL;
    q->size = 500001;
    return q;
}
// cretes customer with scanf data
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
// creates node to be added to queue with customer data inside
node* createNode(customer* curCustomer){
    customer * new_customer = curCustomer;
    node* curNode = malloc(sizeof(node));
    curNode -> cus = new_customer;
    curNode -> next = NULL;
    return curNode;
}

// adds node to a queue
void enqueue(queue* this_queue, node* this_node){
    if (this_queue-> front == NULL){
        this_queue->front = this_node;
        this_queue->back = this_node;
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
// finds the queue value of specificed customer from all the queues
void findQueue(queue ** allQs, customer* new_customer){
    for (int b = 0;b < 13;b++){
            printf("b %d ",b);
            if ((new_customer->firstLetter - 'A') % 13 == b){
                node* new_node = createNode(new_customer);
                if (b == 0){
                    int small = smallestQ(allQs);
                    printf(" small %d ", small);
                    enqueue(allQs[small], new_node);


                }
                else{
                printf("%s ", new_node->cus->name);
                enqueue(allQs[b], new_node);
                }

            }
        }


}
void freeCus(customer* this_customer){
    this_customer->name = NULL;
    free(this_customer);
}

void freeNode(node* this_node){
    free(this_node);
}
queue * dequeue(queue* this_queue, node* this_node){
    //looks for this node than creats tmp equal to it and bridges one previous to this_nodes next han free tmp with freeCus() freeNode()
    node*tmp = this_node;
    if (this_queue->back == this_node){
        this_queue ->front = NULL;
        this_queue-> back = NULL;
        
        
    }
    else if (this_node->next == NULL){
        this_queue->front = NULL;
        this_queue->back = NULL;
    }
    else if(this_node->next->next == this_queue->back && this_node->next != NULL ){
        this_queue->front = this_node->next;
        this_queue->back = this_node->next->next;
    }
    else if (this_node->next != NULL){
        this_queue->front = this_node->next;
        
    }
    //freeCus(this_node->cus);
    //freeNode(this_node);
    return this_queue;




/*

test case

17 3
TANVIR 10 2
ARUP 8 4
TRAVIS 40 5
LILY 5 10
XIE 60 15
GUSTAVO 55 16
JOSE 20 23
DANIEL 20 27
VENU 24 28
ANEESHA 70 29
ANSH 6 35
GUHA 40 36
MEADE 60 38
MASON 12 40
NELLY 10 150
SHARON 5 5000
LEAVENS 2 9000



*/
    

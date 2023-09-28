#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
void dequeue(queue* this_queue, node* this_node);
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
    for (int j = 0; j < 13;j++){
        if (allQs[j]->size <= 500000){
            qNumbers[count] = allQs[j]->front->cus->queue;
            qSizes[count] = allQs[j]->size;
            count++;
        }
    }
    count = 0;

    printf("\n%d\n", totalQs);
    int remainingQs = 0;
    int y = 0;
    int start = 0;
    int end = 0;
    //add is how many booths with queue value of booths
    // remain is how main with queue value of booths-1
    int adder = booths%totalQs;
    int boothC = adder;
    int remain = totalQs/booths;
    printf("%d", adder);
    for (int j = 0; j < booths;j++){
        printf("Booth %d\n", j+1);
        if (boothC != 0){
            count = start+1;
            end = start + adder;
            node* low = allQs[qNumbers[start]]->front;
            node* nexLow = NULL;
            for (int l = 0; l < totalCus(qSizes, start, end); l++){
                if (low->cus->timeEnter > allQs[qNumbers[count]]->front->cus->timeEnter){
                    nexLow = low;
                    low = allQs[qNumbers[count]]->front;
                    count++;
                }
                else if (low->cus->timeEnter > allQs[qNumbers[count+1]]->front->cus->timeEnter){
                    nexLow = low;
                    low = allQs[count]->front;
                    if (count != end){
                        low = allQs[qNumbers[start+1]]->front;
                        count++;
                    }
                    else{
                        low = allQs[qNumbers[start]]->front;
                    }
                }

                else if (nexLow->cus->timeEnter > allQs[qNumbers[count]]->front->cus->timeEnter){
                    nexLow = allQs[qNumbers[count]]->front;
                }
                printf("%s from line %d checks out at time %d", low->cus->name, low->cus->queue, nexLow->cus->timeEnter);
                printf("\n");
                dequeue(allQs[qNumbers[count]], low);
                low = nexLow;
                nexLow = NULL;
                count = start+1;
            }
        start = end+1;
        end = start + adder;
        boothC--;
        }
        end = start + remain;
        if (remain > 0){
           count = start+1;
            end = start + adder;
            node* low = allQs[qNumbers[start]]->front;
            node* nexLow = NULL;
            for (int l = 0; l < totalCus(qSizes, start, end); l++){
                if (low->cus->timeEnter > allQs[qNumbers[count]]->front->cus->timeEnter){
                    nexLow = low;
                    low = allQs[qNumbers[count]]->front;
                    count++;
                }
                else if (low->cus->timeEnter > allQs[qNumbers[count+1]]->front->cus->timeEnter){
                    nexLow = low;
                    low = allQs[qNumbers[count]]->front;
                    if (start + count != end){
                        low = allQs[qNumbers[start+1]]->front;
                        count++;
                    }
                    else{
                        count = 1;
                        low = allQs[qNumbers[start]]->front;
                    }
                }
                printf("%s from line %d checks out at time %d", low->cus->name, low->cus->queue, nexLow->cus->timeEnter);
                dequeue(allQs[qNumbers[count]], low);
                low = nexLow;
                nexLow = NULL;
            }
        }
        printf("\n");

    }


    return 0;
}
int totalCus(int qSizes[12], int star, int end){
    int i = 0;
    int total = 0;
    for ( i  = star; i < end; i++){
        total += qSizes[i];
    }
    return total;
}
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
queue* createQueue(){
    queue* q = malloc(sizeof(queue));
    q->front = NULL;
    q->back = NULL;
    q->size = 500001;
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

void dequeue(queue* this_queue, node* this_node){
    //looks for this node than creats tmp equal to it and bridges one previous to this_nodes next han free tmp with freeCus() freeNode()
    node*tmp = this_node;
    if (this_queue->back == this_node){
        this_queue ->front = NULL;
        this_queue-> back = NULL;
        freeCus(this_node->cus);
        freeNode(this_node);
    }
    else if (this_queue->front->next != NULL){
        this_queue->front = this_queue->front->next;
        freeCus(tmp->cus);
        freeNode(tmp);
    }
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

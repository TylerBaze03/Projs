<<<<<<< HEAD
// THIS PROGRAM DOES NOT WORK I GOT A 50 ON IT FOR SEGFAULTING SOMEWHERE IDK
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITSIZE 10
#define MAXLEN 50
#define MAXROWS 100000



// Tyler Bazemore
// COP3503C Assignment P1
// 9/9/2023



typedef struct order{
    int s_seat;
    int e_seat;
    char* name;
} order;

typedef struct theaterrow{
    order** list_orders;
    int max_size;
    int cur_size;
} theaterrow;

order* make_order(int start, int end, char* this_name);
theaterrow* make_empty_row();
int conflict(order* order1, order* order2);
int can_add_order(theaterrow* this_row, order* this_order);
int add_order(theaterrow* this_row, order* this_order);
char* get_owner(theaterrow** theater, int row, int seat_num);
char* get_row_owner(theaterrow* this_row, int seat_num);
int contains(order* myorder, int seat_no);
void free_order(order* this_order);
void free_row(theaterrow* this_row);

int main(){

    theaterrow** amc = calloc(MAXROWS+1, sizeof(theaterrow*));
    for (int j = 0; j < MAXROWS; j++){
        amc[j] = make_empty_row();
    }
    char* command = calloc(MAXLEN+1,sizeof(char));
    char* buy_name = calloc(MAXLEN+1, sizeof(char));
    int buyer_row = 0, buyer_s = 0, buyer_e = 0;
    scanf("%s", command);
    const char *buy = "BUY";
    const char *look = "LOOKUP";
    const char *quit = "QUIT";
    if(strcmp(command, buy) == 0){
        scanf("%d %d %d %s", &buyer_row, &buyer_s, &buyer_e, buy_name);
    }

    else if(strcmp(command, look) == 0){
        scanf("%d %d", &buyer_row, &buyer_s);
    }
    fflush(stdin);

    while(strcmp(command, quit) != 0){
        buyer_row --;

        if(strcmp(command, buy) == 0){
            order* new_order = make_order(buyer_s, buyer_e, buy_name);

            int add_val = can_add_order(amc[buyer_row], new_order);
            if (add_val == 0){
                int order_bool = add_order(amc[buyer_row], new_order);
                if (order_bool == 1){
                    printf("SUCCESS\n");
                }
                else(printf("FAILURE\n"));
            }
            else if(add_val == 1){
                printf("FAILURE\n");
            }
            free_order(new_order);
        }

        else if(strcmp(command, look) == 0){
            char* seat_own = calloc(MAXLEN+2, sizeof(char));
            seat_own = get_owner(amc, buyer_row, buyer_s);
            fflush(stdout);
            if (seat_own != NULL){
                printf("%s\n", seat_own);

            }
            else if (seat_own == NULL){
                printf("No one\n");
            }
        }
        else{
        }
        buyer_row = 0;
        buyer_s = 0;
        buyer_e = 0;
        printf("Input next command\n");
        scanf("%s", command);
        if(strcmp(command, buy) == 0){
            scanf("%d %d %d %s", &buyer_row, &buyer_s, &buyer_e, buy_name);
        }

        if(strcmp(command, look) == 0){
            scanf("%d %d", &buyer_row, &buyer_s);
        }
    }

    for(int k = 0;k<MAXROWS+1;k++){
        free_row(amc[k]);

    }
    free(amc);
    free(command);
    free(buy_name);


    return 0;
}

// Returns a pointer to a dynamically allocated order storing the given
// start row, end row, and the name this_name. Note: strcpy should be
// used to copy the contents into the struct after its name field is
// dynamically allocated.
order* make_order(int start, int end, char* this_name){
    order* newitem = malloc(sizeof(order));
    newitem->name = calloc(sizeof(this_name)+2, sizeof(char));
    newitem -> s_seat = 0;
    newitem -> e_seat = 0;
    strcpy(newitem->name, this_name);
    newitem->s_seat = start;
    newitem->e_seat = end;
    return newitem;
}

// This function will allocate the memory for one theaterrow, including
// allocating its array of orders to a default maximum size of 10, and
// setting its current size to 0
theaterrow* make_empty_row(){
    theaterrow* empty_row = malloc(sizeof(theaterrow));
    empty_row->list_orders = calloc(INITSIZE+1, sizeof(order*));
    empty_row->max_size = 10;
    empty_row->cur_size = 0;
    return empty_row;
}

// This function returns 1 if the seat number seat_no is contained in
// the range of seats pointed to by myorder, and returns 0 otherwise.
int contains(order* myorder, int seat_no){
    int order_min = seat_no - myorder->s_seat , order_max = seat_no - myorder->e_seat ;
    if((order_min) * (order_max) <= 0){
        return 1;
    }
    else if(((seat_no - myorder->s_seat) * (seat_no - myorder->e_seat)) > 0){
        return 0;
    }


}

// Assuming that order1 and order2 point to orders on the same row, this
// function returns 1 if the orders conflict, meaning that they share
// at least 1 seat in common, and returns 0 otherwise.
int conflict(order* order1, order* order2){
    int container = 0, nocontainer = 0;
    for (int i = order1->s_seat;i <= order1->e_seat;i++){
        if((contains(order2 , i) == 1)){
            container++;
        }
        else if(contains(order2 , i)  == 0){
            nocontainer++;
        }
    }
    if (container > 0){
        return 1;
    }
    else if (container == 0){
        return 0;
    }
}


// Returns 0 if the order pointed to by this_order can be added to the
// row pointed to by this_row. Namely, 0 is returned if and only if
// this_order does NOT have any seats in it that are part of any order
// already on this_row.
int can_add_order(theaterrow* this_row, order* this_order){
    if (this_row->cur_size == 0){
        return 0;
    }
    for(int i = 0;i < this_row->cur_size-1;i++){
        if(conflict(this_order, this_row->list_orders[i] ) == 1){
                return 1;
            }
        else if(conflict(this_order,this_row->list_orders[i] ) == 0){
            ;
        }
    }
    return 0;
}


// This function tries to add this_order to this_row. If successful,
// the order is added and 1 is returned. Otherwise, 0 is returned and
// no change is made to this_row. If the memory for this_row is full,
// this function will double the maximum # of orders allocated for the
// row (via realloc), before adding this_order, and adjust max_size and
// cur_size of this_row.
int add_order(theaterrow* this_row, order* this_order){
    if (this_row->cur_size == this_row->max_size) {
        this_row->list_orders = realloc(this_row->list_orders, (2*this_row->max_size)*sizeof(order*));
        this_row->max_size *= 2;
        this_row->list_orders[this_row->cur_size] = this_order;
        this_row->cur_size++;

        return 1;
    }
    else if(this_row->cur_size < this_row->max_size){
        this_row->list_orders[this_row->cur_size] = this_order;
        this_row->cur_size++;
        return 1;
    }

    return 0;
}


// If seat_num in the row pointed to by this_row is occupied, return a
// pointer to the string storing the owner’s name. If no one is sitting
// in this seat, return NULL.
char* get_row_owner(theaterrow* this_row, int seat_num){
    char* return_name = calloc(MAXLEN+1, sizeof(char));
    for(int i = 0;i < this_row->cur_size;i++){
        if(contains(this_row->list_orders[i], seat_num) == 1){
            return_name = this_row->list_orders[i]->name;
            return return_name;
        }
    }
    free(return_name);
    return NULL;
}
// If seat_num seat number in row number row is occupied, return a
// pointer to the owner’s name. Otherwise, return NULL.
char* get_owner(theaterrow** theater, int row, int seat_num){
    char* null_name = calloc(0, sizeof(char));
    null_name = '\0';
    char* return_name = calloc(MAXLEN+1, sizeof(char));
    if ((get_row_owner(theater[row], seat_num)) == NULL){
        return null_name;
    }
    else{
        char* name = get_row_owner(theater[row], seat_num);
        return_name = get_row_owner(theater[row], seat_num);
        return return_name;
    }
}



void free_order(order* this_order){
    free(this_order->name);

    free(this_order);


}


void free_row(theaterrow* this_row){
    for (int i = 0; i<this_row->max_size;i++){
        free_order(this_row->list_orders[i]);
    }
    free(this_row->list_orders);
    free(this_row);
}
=======
// THIS PROGRAM DOES NOT WORK I GOT A 50 ON IT FOR SEGFAULTING SOMEWHERE IDK
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITSIZE 10
#define MAXLEN 50
#define MAXROWS 100000



// Tyler Bazemore
// COP3503C Assignment P1
// 9/9/2023



typedef struct order{
    int s_seat;
    int e_seat;
    char* name;
} order;

typedef struct theaterrow{
    order** list_orders;
    int max_size;
    int cur_size;
} theaterrow;

order* make_order(int start, int end, char* this_name);
theaterrow* make_empty_row();
int conflict(order* order1, order* order2);
int can_add_order(theaterrow* this_row, order* this_order);
int add_order(theaterrow* this_row, order* this_order);
char* get_owner(theaterrow** theater, int row, int seat_num);
char* get_row_owner(theaterrow* this_row, int seat_num);
int contains(order* myorder, int seat_no);
void free_order(order* this_order);
void free_row(theaterrow* this_row);

int main(){

    theaterrow** amc = calloc(MAXROWS+1, sizeof(theaterrow*));
    for (int j = 0; j < MAXROWS; j++){
        amc[j] = make_empty_row();
    }
    char* command = calloc(MAXLEN+1,sizeof(char));
    char* buy_name = calloc(MAXLEN+1, sizeof(char));
    int buyer_row = 0, buyer_s = 0, buyer_e = 0;
    scanf("%s", command);
    const char *buy = "BUY";
    const char *look = "LOOKUP";
    const char *quit = "QUIT";
    if(strcmp(command, buy) == 0){
        scanf("%d %d %d %s", &buyer_row, &buyer_s, &buyer_e, buy_name);
    }

    else if(strcmp(command, look) == 0){
        scanf("%d %d", &buyer_row, &buyer_s);
    }
    fflush(stdin);

    while(strcmp(command, quit) != 0){
        buyer_row --;

        if(strcmp(command, buy) == 0){
            order* new_order = make_order(buyer_s, buyer_e, buy_name);

            int add_val = can_add_order(amc[buyer_row], new_order);
            if (add_val == 0){
                int order_bool = add_order(amc[buyer_row], new_order);
                if (order_bool == 1){
                    printf("SUCCESS\n");
                }
                else(printf("FAILURE\n"));
            }
            else if(add_val == 1){
                printf("FAILURE\n");
            }
            free_order(new_order);
        }

        else if(strcmp(command, look) == 0){
            char* seat_own = calloc(MAXLEN+2, sizeof(char));
            seat_own = get_owner(amc, buyer_row, buyer_s);
            fflush(stdout);
            if (seat_own != NULL){
                printf("%s\n", seat_own);

            }
            else if (seat_own == NULL){
                printf("No one\n");
            }
        }
        else{
        }
        buyer_row = 0;
        buyer_s = 0;
        buyer_e = 0;
        printf("Input next command\n");
        scanf("%s", command);
        if(strcmp(command, buy) == 0){
            scanf("%d %d %d %s", &buyer_row, &buyer_s, &buyer_e, buy_name);
        }

        if(strcmp(command, look) == 0){
            scanf("%d %d", &buyer_row, &buyer_s);
        }
    }

    for(int k = 0;k<MAXROWS+1;k++){
        free_row(amc[k]);

    }
    free(amc);
    free(command);
    free(buy_name);


    return 0;
}

// Returns a pointer to a dynamically allocated order storing the given
// start row, end row, and the name this_name. Note: strcpy should be
// used to copy the contents into the struct after its name field is
// dynamically allocated.
order* make_order(int start, int end, char* this_name){
    order* newitem = malloc(sizeof(order));
    newitem->name = calloc(sizeof(this_name)+2, sizeof(char));
    newitem -> s_seat = 0;
    newitem -> e_seat = 0;
    strcpy(newitem->name, this_name);
    newitem->s_seat = start;
    newitem->e_seat = end;
    return newitem;
}

// This function will allocate the memory for one theaterrow, including
// allocating its array of orders to a default maximum size of 10, and
// setting its current size to 0
theaterrow* make_empty_row(){
    theaterrow* empty_row = malloc(sizeof(theaterrow));
    empty_row->list_orders = calloc(INITSIZE+1, sizeof(order*));
    empty_row->max_size = 10;
    empty_row->cur_size = 0;
    return empty_row;
}

// This function returns 1 if the seat number seat_no is contained in
// the range of seats pointed to by myorder, and returns 0 otherwise.
int contains(order* myorder, int seat_no){
    int order_min = seat_no - myorder->s_seat , order_max = seat_no - myorder->e_seat ;
    if((order_min) * (order_max) <= 0){
        return 1;
    }
    else if(((seat_no - myorder->s_seat) * (seat_no - myorder->e_seat)) > 0){
        return 0;
    }


}

// Assuming that order1 and order2 point to orders on the same row, this
// function returns 1 if the orders conflict, meaning that they share
// at least 1 seat in common, and returns 0 otherwise.
int conflict(order* order1, order* order2){
    int container = 0, nocontainer = 0;
    for (int i = order1->s_seat;i <= order1->e_seat;i++){
        if((contains(order2 , i) == 1)){
            container++;
        }
        else if(contains(order2 , i)  == 0){
            nocontainer++;
        }
    }
    if (container > 0){
        return 1;
    }
    else if (container == 0){
        return 0;
    }
}


// Returns 0 if the order pointed to by this_order can be added to the
// row pointed to by this_row. Namely, 0 is returned if and only if
// this_order does NOT have any seats in it that are part of any order
// already on this_row.
int can_add_order(theaterrow* this_row, order* this_order){
    if (this_row->cur_size == 0){
        return 0;
    }
    for(int i = 0;i < this_row->cur_size-1;i++){
        if(conflict(this_order, this_row->list_orders[i] ) == 1){
                return 1;
            }
        else if(conflict(this_order,this_row->list_orders[i] ) == 0){
            ;
        }
    }
    return 0;
}


// This function tries to add this_order to this_row. If successful,
// the order is added and 1 is returned. Otherwise, 0 is returned and
// no change is made to this_row. If the memory for this_row is full,
// this function will double the maximum # of orders allocated for the
// row (via realloc), before adding this_order, and adjust max_size and
// cur_size of this_row.
int add_order(theaterrow* this_row, order* this_order){
    if (this_row->cur_size == this_row->max_size) {
        this_row->list_orders = realloc(this_row->list_orders, (2*this_row->max_size)*sizeof(order*));
        this_row->max_size *= 2;
        this_row->list_orders[this_row->cur_size] = this_order;
        this_row->cur_size++;

        return 1;
    }
    else if(this_row->cur_size < this_row->max_size){
        this_row->list_orders[this_row->cur_size] = this_order;
        this_row->cur_size++;
        return 1;
    }

    return 0;
}


// If seat_num in the row pointed to by this_row is occupied, return a
// pointer to the string storing the owner’s name. If no one is sitting
// in this seat, return NULL.
char* get_row_owner(theaterrow* this_row, int seat_num){
    char* return_name = calloc(MAXLEN+1, sizeof(char));
    for(int i = 0;i < this_row->cur_size;i++){
        if(contains(this_row->list_orders[i], seat_num) == 1){
            return_name = this_row->list_orders[i]->name;
            return return_name;
        }
    }
    free(return_name);
    return NULL;
}
// If seat_num seat number in row number row is occupied, return a
// pointer to the owner’s name. Otherwise, return NULL.
char* get_owner(theaterrow** theater, int row, int seat_num){
    char* null_name = calloc(0, sizeof(char));
    null_name = '\0';
    char* return_name = calloc(MAXLEN+1, sizeof(char));
    if ((get_row_owner(theater[row], seat_num)) == NULL){
        return null_name;
    }
    else{
        char* name = get_row_owner(theater[row], seat_num);
        return_name = get_row_owner(theater[row], seat_num);
        return return_name;
    }
}



void free_order(order* this_order){
    free(this_order->name);

    free(this_order);


}


void free_row(theaterrow* this_row){
    for (int i = 0; i<this_row->max_size;i++){
        free_order(this_row->list_orders[i]);
    }
    free(this_row->list_orders);
    free(this_row);
}
>>>>>>> b756d6d (Updating repositroy using git)

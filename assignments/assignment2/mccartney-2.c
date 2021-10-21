// https://www.geeksforgeeks.org/doubly-linked-list/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int N=3;
int pid, tid1, tid2;
int size;
pthread_t thread;

/* Node of a doubly linked list */
struct Node {
	int data;
	struct Node* next; // Pointer to next node in DLL
	struct Node* prev; // Pointer to previous node in DLL
};



// even producer
int produce2(int size) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = node;
    while (1) {
        if (N % 2 != 0) {
            N=N+1;
            size = size + 1;
            node = N;
            int n = rand() % 50 / 2;
                while (n % 2 != 0) {
                    n = rand() % 50 / 2;
                }
                addTail(&N, n, size);
                printf("Producer 2: Current Node: %d.\n", n);
        } else {
            produce1();
            sleep(100000);
            return(0);
        }
    }
}

// odd producer
int produce1(int size) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = node;
    while (1) {
        if (N % 2 == 0) {
            if (N < 50) {
                N = N+1;
                size = size + 1;
                node = N;
                int n = (rand() % 50 / 2) + 1;
                while (n % 2 == 0) {
                    n = (rand() % 50 / 2) + 1;
                }
                addTail(&N, n, size);
                printf("Producer 1: Current Node: %d.\n", n);
            } else {
                consumer1(size);
                sleep(100000);
                return(0); 
            }
        } else {
            produce2(size);
            sleep(100000);
            return(0);
        }
    }
}

// even consumer
int consumer2(int size) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = node;
    while (1) {
        if (N % 2 != 0) {
            if (N > 0) { 
                N=N-1;
                size = size - 1;
                node = N;
                int n = rand() % 50 / 2;
                while (n % 2 != 0) {
                    n = rand() % 50 / 2;
                }
                removeHead(&N, n, size);
                printf("Consumer 2: Current Node: %d.\n", n);
            } else {
                produce1(size);
                sleep(100000);
                return(0); 
            }
        } else {
            consumer1(size);
            sleep(100000);
            return(0);
        }
    }
}

// odd consumer
int consumer1(int size) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = node;
    while (1) {
        if (N % 2 == 0) {
            if (N > 0) {    
                N=N-1;
                size = size - 1;
                int n = (rand() % 50 / 2) + 1;
                while (n % 2 == 0) {
                    n = (rand() % 50 / 2) + 1;
                }
                node = N;
                removeHead(&N, n, size);
                printf("Consumer 1: Current Node: %d.\n", n);
            } else {
                produce1(size);
                sleep(100000);
                return(0); 
            }
        } else {
            consumer2(size);
            sleep(100000);
            return(0);
        }
    }
}

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void addTail(struct Node** tail_node, int new_data, int size)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *tail_node; 

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = &tail_node;
	new_node->prev = NULL;

    if ( size < 31) {
	/* 4. change prev of head node to new node */
        if ((*tail_node) != NULL)
            (*tail_node)->next = new_node;
    } else {
        printf("----------------------------------------Overflow!\n");
        printf("Consumers' turn to take some nodes\n");
        consumer2(size);
    }
        while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

    return;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void removeHead(struct Node** head_node, int new_data, int size)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_node; /* used in step 5*/
    new_node->data = NULL;

    // the next node becomes the head node
	new_node->next = &head_node;
    // and the node that was consumed is dropped
    new_node->prev = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
    if (size < 0) {
        if (*head_node != NULL) {
            new_node->prev = NULL;
        }
    } else {
        printf("---------------------------------------Underflow\n");
        printf("Producers' turn to make more nodes\n");
        produce2(size);
	}	
	return;
}


int main() {
	pid =fork();
    if(N > 0) {
        printf("Parent PID=%d.\n",pid);
        while (N > 0) {
            if (pid < 0 ) {
                printf("Fork failure.\n");
                break;
            }
            else if (pid > 0) {
                consumer1(size);
            }
        } 
    }
    if (N == 0) {
        printf("Child PID=%d.\n",pid);
        tid1 = pthread_create(&thread,NULL,(void *)produce1, (void *)0);
        if (tid1 < 0 ) printf("1st thread_create failure.\n");
        tid2 = pthread_create(&thread,NULL,(void *)produce2, (void *)0);
        if (tid2 < 0 ) printf("2nd thread_create failure.\n");
        thread = pthread_join(thread, NULL);
        
    }
}
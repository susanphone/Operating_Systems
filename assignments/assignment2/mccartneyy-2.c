#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int pid, tid1, tid2;
pthread_t thread;
int node_list;

struct Node {
	int data;
	struct Node* next; // Pointer to next node
	struct Node* prev; // Pointer to previous node
};

void *add_tail(struct Node* last_node, int d);
void *remove_head(struct Node* node);


// produces nodes that are even numbered
struct Node producer2(){
    struct Node* new_node;
        while (1) {
        // if the buffer is full, remove the head node
	    if (node_list > 30) {
            printf("Overflow!\n");
            new_node = new_node->prev;
            // find the head node
            while (new_node != NULL)
                new_node = new_node->prev;
            // once head node is found, remove that head node
            remove_head(new_node);
        }
        
        new_node = new_node->next;
        // find the tail node
        while (new_node->next != NULL)
            new_node = new_node->next;
        // once tail is found, generate a random value
        new_node->data = rand() % 50 / 2;
        // add node to the end of the list in the buffer
        add_tail(new_node, new_node->data);

        // once node is added to the buffer, increase the length of the list
        node_list += 1;
	printf("Produce1: Current N=%d.\n", new_node->data);
    }
}

// produces nodes that are odd numbered
struct Node producer1(){
    struct Node* new_node;
        while (1) {
	    if (node_list > 30) {
            printf("Overflow!\n");
            new_node = new_node->prev;
            while (new_node != NULL)
                new_node = new_node->prev;
            remove_head(new_node);
        }
        new_node = new_node->next;
        while (new_node->next != NULL) {
            new_node = new_node->next;
            }
        new_node->data = (rand() % 50 / 2)+1;
        add_tail(new_node, new_node->data);
        //  once a node is added to the buffer, increase the length of the list
        node_list += 1;
	printf("Produce1: Current N=%d.\n", new_node->data);
    }
}

// removess nodes that are even numbered
void consumer2(struct Node* current_node) {
    while (1) {
        // if thare are no nodes in the buffer, print underflow
        if (node_list <=0) {
            printf("Underflow!\n");
            current_node = current_node->next;
            while (current_node->next != NULL)
                current_node = current_node->next;
            add_tail(current_node, current_node->data);
        }
        // otherwise remove the node from the buffer
        current_node->data = NULL;
        remove_head(current_node);
        // decrease the length of the buffer by one/
    	node_list-= 1;
	printf("Consumer2: Current N=%d.\n", current_node->data);
    }
}

// removes nodes that are odd numbered
void consumer1(struct Node* current_node) {
    while (1) {
         // if thare are no nodes in the buffer, print underflow
        if (node_list <=0) {
            printf("Underflow!\n");
            current_node = current_node->next;
            while (current_node->next != NULL)
                current_node = current_node->next;
            add_tail(current_node, current_node->data);
        }
        // otherwise remove the node from the buffer
        current_node->data = NULL;
        remove_head(current_node);
        // decrease the length of the buffer by one/
    	node_list-= 1;
	printf("Consumer2: Current N=%d.\n", current_node->data);
    }
}


// add a new node to the end of the buffer
void *add_tail(struct Node* last_node, int d) {
    // if the node in empty, add a random value
    if (d == NULL) {
        d = rand() % 50;
    }
    struct Node* last = last_node;
    // add the data to the last node
    // add space to the buffer for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    d = new_node->data;
    // determine which producer to use based on if the node is even or odd
    if (d % 2 == 0)
        producer2();
    else 
        producer1();
    // the new node is set to the last node
    new_node = last->next;
    return;
}

// remove the head node from the buffer
void *remove_head(struct Node* head_node) {
    // determine which consumer will take the node
    if (head_node->data % 2 == 0)
        consumer2(head_node);
    else
        consumer1(head_node);
    // the new head becomes the next node.
    head_node = head_node->next;
    return;
}


int main() {
    // copied from class resources
    struct Node* node;
    printf(&node);
    node_list = 3;
    int pid, pid1;
    printf(pid, pid1);
	pid = fork();
	if (pid < 0 )
		printf("Fork failure.\n");
	else if (node_list > 0)
	{
		printf("Parent PID=%d.\n",pid);
		remove_head(node);
        printf(pid);
	} else {
   		pid1 = fork();
	        if (pid1 < 0 )
		       { printf("Fork failure.\n");}
		    else if (node_list > 0 && node_list % 2 != 0){
		        printf("Child PID=%d.\n",pid1);
			    add_tail(node, node->data);
			} else {
			  printf("Child PID=%d.\n",pid1);
			  add_tail(node, node->data);
              printf(&node);
			}
        printf("Child PID=%d.\n",pid);
        tid1 = pthread_create(&thread,NULL,(void *)producer1, (void *)0);
        if (tid1 < 0 ) printf("1st thread_create failure.\n");
        tid2 = pthread_create(&thread,NULL,(void *)producer2, (void *)0);
        if (tid2 < 0 ) printf("2nd thread_create failure.\n");
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        printf(tid1);
        printf(tid2);
        return(0);
    }
}
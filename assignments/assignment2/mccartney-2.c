// Susan McCartney
// CSCI 460: Program 2
// October 21, 2021
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// no more than 30 node in the head_node at a time
int CUR_LENGTH = 0;
int MAX_NODES = 30;
int NUM_PROD_ITEMS = 0;
int MAX_PROD_ITEMS = 100;

// Thread things
pthread_t odd_producerT, even_producerT, odd_consumerT, even_consumerT;
// pthread_mutex lock and unlock, lock is like a key, the one with the key
// (i.e. producer or consumer) can either add or remove nodes from the buffer.
pthread_mutex_t lock;
int tid1, tid2, tid3, tid4;

// DLL
struct Node *head_node = NULL;

// set up the node
struct Node
{
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};

void print_list(char *thread_name, struct Node* head)
{
    printf("%s ", thread_name);
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// add a new node to the head_node
void append(struct Node **head, int new_data)
{
    // allocated memory for the new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // keep track of the last node in the buffer
    struct Node *last = *head;

    // add a new value to the new node
    new_node->data = new_data;
    new_node->next = NULL;

    // if head is empty, then the new node becomes the new head
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        CUR_LENGTH = 1;
        return;
    }

    // make sure to add the new node to the end of the buffer
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    // Increment the list length
    CUR_LENGTH = CUR_LENGTH + 1;
}

// remove a node from the head_node
void pop_head(struct Node **head_ref)
{
    // No Nodes at all!
    if (*head_ref == NULL)
        return;
    // keep track of the old head
    struct Node *old_head = *head_ref;

    // old head pops off, and next becomes new head
    *head_ref = old_head->next;

    free(old_head);

    CUR_LENGTH = CUR_LENGTH - 1;
}

// add odd number valued nodes
void odd_producer()
{
    while (NUM_PROD_ITEMS <= MAX_PROD_ITEMS)
    {
        pthread_mutex_lock(&lock);
        print_list("Producer 1 unlock", head_node);
        if (CUR_LENGTH >= MAX_NODES)
        {
            printf("Producer 1: Buffer Full, waiting to add more\n");
            print_list("Producer 1 unlock", head_node);
            pthread_mutex_unlock(&lock);
            sleep(1);
            continue;
        };
        // generate a random odd value
        int val = ((rand() % (25 + 0)) * 2) + 1;

        // add a new node with an odd value
        append(&head_node, val);

        NUM_PROD_ITEMS = NUM_PROD_ITEMS + 1;
        print_list("Producer 1 unlock", head_node);
        pthread_mutex_unlock(&lock);
        printf("Producer 1: %d\n", val);
    }
}

// add even number valued nodes
void even_producer()
{
    while (NUM_PROD_ITEMS <= MAX_PROD_ITEMS)
    {
        pthread_mutex_lock(&lock);
        print_list("Producer 2 lock", head_node);
        if (CUR_LENGTH >= MAX_NODES)
        {
            printf("Producer 2: Buffer Full, waiting to add more\n");
            print_list("Producer 1 unlock", head_node);
            pthread_mutex_unlock(&lock);
            sleep(1);
            continue;
        };
        // generate a random even value
        int val = rand() % 25 * 2;
        // add a new node with an even value
        append(&head_node, val);

        NUM_PROD_ITEMS = NUM_PROD_ITEMS + 1;
        print_list("Producer 2 unlock", head_node);
        pthread_mutex_unlock(&lock);
        printf("Producer 2: %d\n", val);
    }
}

// remove an odd number valued node
void odd_consumer()
{
    int consumerId = 1;
    while (1)
    {
        pthread_mutex_lock(&lock);
        print_list("Consumer 1 lock", head_node);
        // make sure there are nodes in the buffer
        if (CUR_LENGTH <= 0 || head_node == NULL)
        {
            printf("Consumer %d: Waiting for jobs.\n", consumerId);
            print_list("Consumer 1 unlock", head_node);
            pthread_mutex_unlock(&lock);
            sleep(1);
            continue;
        }

        // If the head node has an odd value, pop it
        if (head_node->data % 2 != 0)
        {
            int val_to_pop = head_node->data;
            pop_head(&head_node);
            printf("Consumer %d: %d.\n", consumerId, val_to_pop);
        };
        print_list("Consumer 1 unlock", head_node);
        pthread_mutex_unlock(&lock);
    }
}

// remove an even number valued node
void even_consumer()
{
    int consumerId = 2;
    while (1)
    {
        pthread_mutex_lock(&lock);
        print_list("Consumer 2 lock", head_node);
        if (CUR_LENGTH <= 0 || head_node == NULL)
        {
            printf("Consumer %d: Waiting for jobs.\n", consumerId);
            print_list("Consumer 2 unlock", head_node);
            pthread_mutex_unlock(&lock);
            sleep(1);
            continue;
        }

        // If the head node has an even value, pop it
        if (head_node->data % 2 == 0)
        {
            int val_to_pop = head_node->data;
            pop_head(&head_node);
            printf("Consumer %d: %d\n", consumerId, val_to_pop);
        };
        print_list("Consumer 2 unlock", head_node);
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    // create pthreads for the producers and consumers
    // based off of in class examples
    tid1 = pthread_create(&odd_producerT, NULL, (void *)odd_producer, (void *)0);
    if (tid1 < 0)
        printf("1st thread_create failure.\n");

    tid2 = pthread_create(&even_producerT, NULL, (void *)even_producer, (void *)0);
    if (tid2 < 0)
        printf("2nd thread_create failure.\n");

    tid3 = pthread_create(&odd_consumerT, NULL, (void *)odd_consumer, (void *)0);
    if (tid3 < 0)
        printf("3rd thread_create failure.\n");

    tid4 = pthread_create(&even_consumerT, NULL, (void *)even_consumer, (void *)0);
    if (tid4 < 0)
        printf("4th thread_create failure.\n");

    // initialize a pthread join to make the program work. 
    pthread_join(odd_producerT, NULL);
    pthread_join(even_producerT, NULL);
    pthread_join(odd_consumerT, NULL);
    pthread_join(even_consumerT, NULL);

    return 0;
}

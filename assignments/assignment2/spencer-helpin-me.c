
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// We have to stop sometime, right?
int NUM_PROD_ITEMS = 0;
int MAX_PROD_ITEMS = 100;

// no more than 30 node in the head_node at a time
int CUR_LENGTH = 0;
int MAX_NODES = 30;

// Thread things
pthread_t odd_producerT, even_producerT, odd_consumerT, evenConsumerT;
pthread_mutex_t lock;
int tid1, tid2, tid3, tid4;

// DLL
struct Node *head_node = NULL;

struct Node
{
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};

// add a new node to the head_node
void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        CUR_LENGTH = 1;
        return;
    }

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
    {
        return;
    }

    struct Node *old_head = *head_ref;

    *head_ref = old_head->next;

    free(old_head);

    CUR_LENGTH = CUR_LENGTH - 1;
}

void odd_producer()
{
    while (NUM_PROD_ITEMS <= MAX_PROD_ITEMS)
    {
        pthread_mutex_lock(&lock);
        if (CUR_LENGTH >= MAX_NODES)
        {
            printf("Producer 1: Buffer Full, waiting to add more\n");
            pthread_mutex_unlock(&lock);
            sleep(1);
            continue;
        };
        int val = ((rand() % (25 + 0)) * 2) + 1;
        // DOes head_node need a *?
        append(&head_node, val);

        NUM_PROD_ITEMS = NUM_PROD_ITEMS + 1;
        pthread_mutex_unlock(&lock);
        printf("Producer 1: %d\n", val);
    }
    //TODO: Say we done
}

void even_producer()
{
    while (NUM_PROD_ITEMS <= MAX_PROD_ITEMS)
    {
        pthread_mutex_lock(&lock);
        if (CUR_LENGTH >= MAX_NODES)
        {
            printf("Producer 2: Buffer Full, waiting to add more\n");
            pthread_mutex_unlock(&lock);
            sleep(1);
            continue;
        };
        int val = rand() % 25 * 2;
        append(&head_node, val);

        NUM_PROD_ITEMS = NUM_PROD_ITEMS + 1;
        pthread_mutex_unlock(&lock);
        printf("Producer 2: %d\n", val);
    }
}

void oddConsumer()
{
    int consumerId = 1;
    while (1)
    {
        pthread_mutex_lock(&lock);
        if (CUR_LENGTH <= 0 || head_node == NULL)
        {
            printf("Consumer %d: Waiting for jobs.\n", consumerId);
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
        pthread_mutex_unlock(&lock);
    }
}

void evenConsumer()
{
    int consumerId = 2;
    while (1)
    {
        pthread_mutex_lock(&lock);
        if (CUR_LENGTH <= 0 || head_node == NULL)
        {
            printf("Consumer %d: Waiting for jobs.\n", consumerId);
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
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    tid1 = pthread_create(&odd_producerT, NULL, (void *)odd_producer, (void *)0);
    if (tid1 < 0)
        printf("1st thread_create failure.\n");

    tid2 = pthread_create(&even_producerT, NULL, (void *)even_producer, (void *)0);
    if (tid2 < 0)
        printf("2nd thread_create failure.\n");

    tid3 = pthread_create(&odd_consumerT, NULL, (void *)oddConsumer, (void *)0);
    if (tid3 < 0)
        printf("3rd thread_create failure.\n");

    tid4 = pthread_create(&evenConsumerT, NULL, (void *)evenConsumer, (void *)0);
    if (tid4 < 0)
        printf("4th thread_create failure.\n");

    pthread_join(odd_producerT, NULL);
    pthread_join(even_producerT, NULL);
    pthread_join(odd_consumerT, NULL);
    pthread_join(evenConsumerT, NULL);

    return 0;
}

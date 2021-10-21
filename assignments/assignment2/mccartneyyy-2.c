#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
pthread_mutex_t mutex_lock; //init lock

const int max = 50; //number of message to be sent
pthread_mutex_t lock;
int length; //number of entries in the linked list
pthread_t tid1, tid2, tid3, tid4;

//count is the total number of linkedlist node you have add/remove in producer/consumer

struct Node {
    int data;
    struct Node next;
    struct Node prev;
};

void add_tail(struct Node *node, int d);
void remove_head(struct Node *node, int d);


void product1()
{
    int count = 0;
    while (count < 30)
    {
        int data = (rand() % 50)+1;
        while (data % 2 == 0) {
            data = (rand() % 50 /2)+1;
        }
        if (length == 30)
        {
            pthread_mutex_lock(&mutex_lock); //wait
        }
        add_tail(tail, data);
        printf("producer 1 %d\n", data);
        pthread_mutex_unlock(&mutex_lock); //Release the lock
        count++;
        length++;
        sleep(1);
        return;
    }
}

void consume1()
{
    struct Node* head;
    int count = 0;
    while (count < max)
    {
        sleep(1);
        if (length == 0)
        {
            pthread_mutex_lock(&mutex_lock); //wait
        }
        printf("consumer 1 %d\n", head->data);
        pthread_mutex_unlock(&mutex_lock); //Release the lock
        count++;
        length--;
        return;
    }
}
void product2()
{
    struct Node *new_tail;
    int count = 0;
    while (count < 30)
    {
        int data = rand() % 50;
        while (data % 2 != 0) {
            data = (rand() % 50 /2);
        }
        if (length == 30)
        {
            pthread_mutex_lock(&mutex_lock); //wait
        }
        add_tail(new_tail, data);
        printf("producer 2 %d\n", new_tail->data);
        pthread_mutex_unlock(&mutex_lock); //Release the lock
        count++;
        length++;
        sleep(1);
        return;
    }
}

void consume2()
{
    struct Node *head;
    int count = 0;
    while (count < max)
    {
        sleep(1);
        if (length == 0)
        {
            pthread_mutex_lock(&mutex_lock); //wait
        }
        printf("consumer 2 %d\n", head->data);
        pthread_mutex_unlock(&mutex_lock); //Release the lock
        count++;
        length--;
        return;
    }
}
struct Node *create_node(int d){
    struct Node *tail = malloc(sizeof(struct Node));
    tail->data = d;
    tail->next = NULL;
    return tail;
}

void add_tail(struct Node *node, int d)
{
    struct Node *tmp = create_node(d);
    tmp->next = node;
    node = tmp;
    return;
}

void remove_head(struct Node *node, int d)
{
    if (node == NULL)
    {
        return;
    }
    if (d % 2 == 0)
        consume2();
    else
        consume1();
    
    struct Node *tmp = node->next;
    free(node);
    node = tmp;
    return;
}



int main() {
    struct node *new_node;
    int d1 = rand() % 50;
    int d2 = rand() % 50;
    int d3 = rand() % 50;
    length = 3;
    new_node = create_node(d1);
    new_node = create_node(d2);
    new_node = create_node(d3);
    if (d1 % 2 == 0)
        consume2;
    else
        consume1;
    pthread_mutex_init(&mutex_lock, NULL);
    pthread_create(&tid1, NULL, (void *)product1, NULL); //Determine the thread entry point
    pthread_create(&tid2, NULL, (void *)product2, NULL); //Determine the thread entry point
    pthread_join(tid1, NULL); //Wait for the thread to exit
    pthread_join(tid2, NULL);

    if (length == 0){
        printf("ERROR! List not empty\n");
    }
    exit(0);
}

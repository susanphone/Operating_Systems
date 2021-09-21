#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Queue {
    int head, tail, size; 
    unsigned capacity;
    int array[];

} queue;

struct Memory {
    int job_number;
    int bytes
} job;

// read in command, separate the job number from its 
//bytes, and return command array
struct char_buff *repl_read_command(char *prompt) {
    int command[] = scanf(&prompt);
    for (int i=0; i<len(command); i++) {
        char * token = strtok(command, " ");
    }
    int job_number = command[0];
    int bytes = command[1];
    int page_frames = page_calculator(bytes);
    repl_execute_command(page_frames);

    return command[0], command[1];
}

// calculate the number of page frames need for the job
int page_calculator(struct item *bytes) {
    int page_size = 4069;
    int bytess = repl_read_command(bytes);
    int required_pages = (bytess / page_size);
    int final_amount = ceil(required_pages);
    return final_amount;

    
}
// struct Queue* newQueue(unsigned capacity) {
//     struct Queue* item = (struct Queue*)malloc(sizeof(struct Queue));
//     item->capacity = capacity;
//     item->head = item->page_size = 0;

//     item->tail = capacity - 1;
//     item->array = (int*)malloc(item->capacity * sizeof(int));
//     return item;
// }
    
//add job to queue
void enqueue(struct Queue* queue, int job){
    // add job to queue 
}

//remove from queue if the job is complete
void dequeue(struct job *memo){
    int head;
    head += 1;    
}

int job_to_memory(struct Memory job, int size) {

}

// remove the job from memory and release pages
void remove_job_from_memory(int array[], int size, int job_number) {

}


void repl_execute_command(struct char_buff *buffer) { 
    enqueue();
    dequeue();
    add_to_memory();
    remove_job_from_memory();
   // take completed jobs out of memory
    // put jobs in memory
}

// print the memory out in the command like a memory map table or job map table
void print_memory(struct job *memory, FILE output) {
    struct item *head, *tail;
    if (&head == -1) {
        printf("The queue is empty");
    } else {
        for (int i = head; i <= tail; i++) {
            fprintf(&output, ("%d \n", &memory));
        }
    }
    
}

// exit the program
void exit(char *prompt){
    if (&prompt == "exit") {
        return 0;
    }
}


int main() {
    char *prompt;
    int page_frames[16];
    int *page_frame_pointer = page_frames;
    struct char_buff *buffer;
    FILE *output = fopen("output.txt", "w");

    
    // Setting up REPL
    do {
        int *command = repl_read_command(&prompt);
        if (&prompt == "print") {
            repl_print_memory(&prompt, output);
        }
        if (&prompt == "exit") {
            return 0;
        } else {
            repl_execute_command(&buffer);
        }
    } while (enqueue > 0); 
    



    int fclose(output);
    return 0;
}
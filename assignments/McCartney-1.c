#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Job_Number {
    int job;
    int bytes
} job;

struct Memory_Status {
    int status;
    char state;
    int memory;
} memory_status;

// malloc to memory and remove from queue
// remove job
// have an array of page frames

struct char_buff *repl_read_command(char *prompt) {

}

// add to queue
void enqueue();
//remove from queue
void dequeue();

void repl_execute_command(struct char_buff *buffer) {

}

void repl_print_memory(struct memory_status *memostat, struct job *jerb) {

}


int main() {
    // char_buff * command;
    struct job *jerb;
    struct memory_status *memostat;
    char *prompt;
    struct char_buff *buffer;
    // Setting up REPL
    do {
        int *command = repl_read_command(&prompt);
        repl_execute_command(&buffer);
        repl_print_memory(&jerb, &memostat);
    } while (/* items in the queue */); 
        /* code */
    
    FILE *output = fopen("output.txt", "w");


    fprint("hello");

    int fclose(output);
    return 0;
}
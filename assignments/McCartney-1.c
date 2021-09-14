#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Page_Size[4069];
int head;
int tail;

struct Queue {
    head;
    tail; 
} item;

struct Memory {
    int job;
    int bytes
} job;


struct char_buff *repl_read_command(char *prompt) {
    int command[] = scanf(&prompt);
    for (int i=0; i<len(command); i++) {
       command[i].split(" ");
    }
    int job = command[0];
    int bytes = command[1];
    enqueue(job);
    repl_execute_command(bytes);
}

void enqueue(char *prompt){
    int new_job;
    int head = 0;
    scanf("%d %d", &prompt);
    int tail += 1;
    Page_Size[tail] = new_job;
    //add job to queue
}

//remove from queue if the job is complete
void dequeue(struct job *memo){
    int head;
    head += 1;
    enqueue(head); //move job to done
    
}

void repl_execute_command(struct char_buff *buffer) {
    // take completed jobs out of memory
    // calculate # of pages required for job
    // put jobs in memory
}

void print_memory(struct job *memory, FILE output) {
    if (head == -1) {
        printf("Empty Queue");
    } else {
        for (int i = head; i <= tail; i++) {
            fprintf(&output, ("%d \n", &memory));
        }
    }
    
    // print the memory out in the command like a memory map table or job map table
}
void exit(char *prompt){
    return 0;
}


int main() {
    struct job *jerb;
    char *prompt;
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
    


    fprint("hello");

    int fclose(output);
    return 0;
}
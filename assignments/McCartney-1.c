#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Queue {
    int head, tail, size; 
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
    
//add job to queue
void enqueue(struct Memory* memory){
    int tail;
    tail+=1;
    // add job to queue 
}

//remove from queue if the job is complete
void dequeue(struct Memory* memory){
    int head;
    head += 1;    
}

// divide job into page frames
struct Memory* job_to_memory(struct Memory* memory) {
    int needed_frames = page_calculator(memory->bytes);
    // add job to memory
    return memory->job_number, memory->bytes;
}

// remove the job from memory and release pages
int remove_job_from_memory(int page_frames, struct Memory* memory) {
    int remaining_bytes = memory->bytes;
    int pages = 0;
    while (remaining_bytes != 0) {
        page_frames = 4069;
        remaining_bytes -= page_frames;
        pages += 1;
    }
    return pages;

}


void repl_execute_command(struct char_buff *command[]) {
    struct Memory job_number, bytes;
    int page_frames[16];
    int *page_frame_pointer = page_frames; 
    // if prompt add new job, add to queue
    enqueue(&command[0]);
    // if enough page frames are available, 
    //remove from queue and add to memory
    for (int i = 0; i < page_frames; i++) {
        if(page_frames == 0) {
        dequeue(&command[1,2]);
        job_to_memory(&command[1,2]);
    } else {
        //if job is done, remove from queue
        if(page_frame_pointer != 0) {
            int reset_frames = remove_job_from_memory(page_frames);
            page_frame_pointer[reset_frames];
            dequeue(&command[0]);
        } else {
            //put job in the back of the queue and try a new job
            dequeue(&command);
            enqueue(&command);
            continue;
        }
    }
}}

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
        // struct char_buff *buffer;
    FILE *output = fopen("output.txt", "w");

    
    // Setting up REPL
    do {
        int *command[] = repl_read_command(&prompt[0,1]);
        if (&prompt == "print") {
            repl_print_memory(&prompt, output);
        }
        if (&prompt == "exit") {
            return 0;
        } else {
            repl_execute_command(&command);
        }
    } while (enqueue > 0); 
    


    int fclose(output);
    return 0;
}
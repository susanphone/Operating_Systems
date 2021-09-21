//
// Created by susan on 9/3/21.
//

#ifndef OPERATING_SYSTEMS_ASSIGNMENT1_H
#define OPERATING_SYSTEMS_ASSIGNMENT1_H


struct char_buff *repl_read_command(char *prompt);
void repl_execute_command(struct char_buff *buffer);
int page_calculator(struct item *bytes);
void enqueue(struct Memory* memory);
void dequeue(struct Memory* memory);
struct Memory* job_to_memory(struct Memory* memory);
int remove_job_from_memory(int page_frames, struct Memory* memory);
void repl_execute_command(struct char_buff *command);
void print_memory(struct job *memory, FILE output);
void exit(char *prompt);




#endif //OPERATING_SYSTEMS_ASSIGNMENT1_H

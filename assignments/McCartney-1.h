//
// Created by susan on 9/3/21.
//

#ifndef OPERATING_SYSTEMS_ASSIGNMENT1_H
#define OPERATING_SYSTEMS_ASSIGNMENT1_H


struct char_buff *repl_read_command(char *prompt);
void repl_execute_command(struct char_buff *buffer);
void repl_print_memory(struct memory_status *memostat, struct job *jerb);



#endif //OPERATING_SYSTEMS_ASSIGNMENT1_H

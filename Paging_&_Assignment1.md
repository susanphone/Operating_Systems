# Paging (Paged Memory Allocation)
* Does a program have to be resided completely and contiguously in main memory? NO
* IDEA: DIviding an incoming job into memory blocks (frames) of equal size, which are called pages
* to execute a program, memory manager must do the following:
    1. Decide # of pages
    2. Have enough empty page frames in main memory
    3. Load all the program's pages into them
        Fragmentation 
            - no external frag
            - internal fragmentation can possibly occur in the last page of a job
* Advantage:
    1. memory is certainly used efficiently
    2. no external fragmentation
    3. almost no internal fragmentation
* Drawback? \i{Overhead is increased significantly}. An OS nowadays has to be designed by experts and by substantial teamwork
### How do we manage paging?
1. Job Table
    job #       size        PMT location
    1           26k             xxxxxxx
2. Page Map Table (PMT for each job)
    page #      page frame number in memory
    0                   5
    1                   3
    2                   0  
3. Memory Map Table
    page frame #         status
0       0                 busy
1       1                 --
2       2                 free
3       3                 busy
4       4                 --
5       5                 busy

# Assignment 1
    16 page frames
    page = 4096 bytes
* two kinds of commands
    job_number bytes
    job_number
* also have 
    print
    exit
* FIFO
* goto statement is harmful!
* Can discuss but must be individual assignment

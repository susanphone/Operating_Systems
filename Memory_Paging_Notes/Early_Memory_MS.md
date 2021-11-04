# Early Memory Management System
In the early days, a computer can only have one computer at a time
## Algorithm: Load a job in a single-user system
    (check slides for more details)

* if a program counter is less than or equal to memory size, the program can run
* one program at a time


# Fixed (Static) Partitions
* Single user cannot support multiprogramming
* Static partition is one way to handle multiprogramming
* a program must be entirely stored in the a partition

## What is the drawback of fixed partition?
* If the size of memory does not fit partition size --> poop
* internal fragmentation: partial use of fixed partitions

### How are partition sizes dertermined?
    jobs cannot control, partition size can only be changed on reboot

* If partition size is too large -> waste memory
* If partition size is too small -> large jobs will be rejected

## Algorithm to load a job in fixed partition
    (check slides for more detail)

# Dynamic Partitions
* There is no partition when the computer is turned on
* Available memory is still kept in contiguous blocks, but jobs are given only as much memory as they need
* This does not solve the memory wasting problem

### Example:
    job1, 20k  | 20k |                 |job1|        job1 finishes     |////| 20k free
    job2, 30k  | 30k | job4 finishes   |job2|        job6, 50k         |job2|
    job3, 40k  | 40k | job5, 10k       |job3|                          |job3|
    job4, 40k  | 40k |                 |10k |                          |////|
                                       |free| <- 30k                   |////| 30k free
                                                                        job6, waits

* external fragmentation: within dynamic partition, the allocation of memory create fragments of free memory blocks of allocated memory which are wasted

* When memory is allocated, we can use first-fit or best-fit
    * first-fit allocation method keeps a list of free/busy memory fragments ordered by memory address
    * best-fit allocation method keeps a list of free/busy memory fragments ordered by memory size
### What is the advantage/drawback of first-fit?
* Usually faster +
* Might not use memory efficiently -
### What is the advantage/drawback of best-fit?
* Space efficient +
* slower -

## Algorithm: Dynamic Partition - First-Fit & Best-Fit
    (see slides for more detail)

# Memory Deallocation
* When memory space are not used anymore they must be released back to the system
    * Fix partition: easy, just reset the free/busy status variable
    * Dynamic partition: we need to combine free areas of memory
### Think of 3 situations when a block is to be released:
    See class notes about Memory Deallocation
## Algorithm: Dynamic partition - memory deallocation
    See slides

# Relocatable Dynamic Partitions
* Both of the previous partitions introduce internal/external fragmentations
* Relocatable dynamic partition is a natural solution
* The basic idea is **garbage collection (memory compaction)** - reuse unused memory blocks
### How to do garbage collection?
1. **Bounds Register** is used to store the highest(or lowest) location in memory accesibly by each program
2. **relocation register** contains the value, which could be positive or negative
* look at machine vs assembly language example file

# The drawback of relocatable dynamic partition
* OVERHEAD!
### WHen should we use relocatable dynamic partition?
1. When memory is busy
2. When many jobs are waiting
3. When waiting time is too long
### What can we learn from relocatable dynamic partition?
* Programs do not have to be stored completely in memory
* Programs do not have to be stored contingously in memory

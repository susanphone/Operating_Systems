# Operating Systems (9th edition, by William Stallings, Pearson)
## class schedule
    7 pop-up quizzes, 5 count
    5 homeworks
        multiple choice
        can retake before deadline
    3 tests
        can bring cheatsheet
    3 programs
    1 final project (16%)
        can make decision end of October
        can work with partner
        project ideas on course page
            -raspberry pis
            -implement a file manager
            -barrelfish os

    esus.cs.montana.edu

    Name some Operation Systems:
        iOS
        -have coded on: **unix**/linux
        -Android, **IBM360**

## What is an Operating system:
    part of computing system managing all the hardware and software

### First Part of Course
    How OS works, the related concepts, and algorithms.
### Second Part
    Networks more important in the last 20 years. Distrubuted computing and network operating systems. 
    Computer Architecture and hardware.

### What will happen if you run ```a.out```?
Board(device manager) --> is it (```a.out```) 

in main memory (memory M)?

    -->If not, fetch it (File M)
    --> run it (processor M) --> output in screen, device M
                             --> output in file, file M
    --> Is ```a.out``` changed or not?

## What is OS composed of?
    Memory Manager - main memory
    Processor Manager - allocate the CPU
    Device Manager - monitors, channel and control unit
    File Manager - track every file in the system (files, assembles, compilers, and apps)
    Network Manager -network communications and protocols
### Like a pyramid (look at class notes on D2L)

memory-address.c file

```./a.out``` returns memory addresses in memory-address file
        var and var1 are reverse order
            var 1 2fe3e9dc
            buff  2fe2b150
            var   2fe3eqdc
        this uses a **stack**
        
bytes vs char, char is smaller 4 bytes is 64 char

what does ```cc memory-address.c``` do? does this compile the program? I think so.








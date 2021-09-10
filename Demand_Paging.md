# Demand Paging
Demand Paging only loads a part of a program into memory for running
1. Jobs are still decompsed into equally sized Pages
2. Jobs are initially stored in secondary memory

### Why demand paging is feasible?
* Menu-driven System:
    * add a new record
    * delete a record
    * update a record
    * query
    * ....
#### Locality of Reference

Demand paging allows a user to run jobs with less main memory (this idea of virtual memory: the user would feel that the physical memory is almost infinite. though it is not the case in reality)
* Page Map Table(PMT) need to be modified
            |Page# |  PageFrame# |  inMemory ? | modified ? | referencedRecently?|
            | -----| ----------- | ----------- | ---------- | ------------------ |
    j1:30k  |   0  |    2        |  y          |            |                    |
            |   1  |    5        |  y          |            |                    |     
            |   2  |    0        |  y          |            |                    | 
        

    j2:40k      0       4           y
                1       1           y
                2                   n
                3                   n

    j3:40k      0       6           y
                1       2           y
                2                   n
                3                   n

    Main Memory:
        j1,p2   0
        j2,p1   1
        j3,p1   2
        j1,p0   3
        j2,p0   4
        j1,p1   5
        j3,p0   6
        page size: 10k
* What if I need to access j2,p2?

### How does the computer fetch an instruction?
    see class notes

### What is the average number of searches?
**N**

### Page Interrupt Handler Algorithm
    see class notes
* Although demand paging is a solution to ineficient memory utilization, it does solve all the problems
* **Thrashing** if a large amount of page swapping is performed. the system efficiency is affected
* **page default** a failure to find a page in memory
    |memory|
    |busy  |        while (i < 1,000,000)
    |pi    |            page i
    |busy  |         ---------------
                        page i + 1

## How do we swap a page out of memory?
### FIFO (First in first out)
* FIFO removes the page that has been in the memory the longest

    job request A   B   A   C
    |frame 1|   A   A   A   C   
    |frame 2|       B   B   B
    Secondary:
        A       B   C   C   A->changed?
        B       C   D   D   D
        C       D   E   E   E
        D       E
        E
    
### LRU (Least Recently Used). 
* LRU removes the page that shows the least sign of recent usage.

    job request A   B   A   C
    |frame 1|   A   A
    |frame 2|       B
    secondary:
        A       B   C
        B       C   D   
        C       D   E
        D       E
        E

### LFU (Least Frequently Used)
* LFU removes the page that shows the least amount of recent usage, over certain period of time.

## How do we make use of the PMT(Page Map Table)?
* in memory? modified? referenced recently?
    (status)
        1       0           0
        1       0           1   not modified but has been referenced
        1       1           0 -> impossible
        1       1           1   modified and referenced
## How to improve the performance of demand paging?
* **Working Set**: a set of pages in memory which do not need to be swapped out back and forth. However, Identifying work set is not easy.

## Summary
1. Virtual meory is introduced. 
2. Utilizes memory more efficiently. 
3. Overhead is heavy
        program:    |main|

                    |f1: |
                    |    |

                    |f2: |

## Why Buddy System?
* In real systems, a page is usually of size 2^a- a power of 2.
* A combination of dynamic partition and paging
* Allocation algorithm
    see notes
    take free block, split into two equal size blocks. Bi -> Bi1 and Bi2
* Deallocation Algorithm
    see notes
    take free block, find another free block, combine the two. -> Bi + Bj -> Bk
* Buddy memory written class example
    Memory                      1M
    A: 100k     |A=128k |  128k  | 256k      | 512k                  |
    B: 240k     |A=128k |  128k  | B=256k    | 512k                  |
    C: 64k      |A      |C=64|64k|    B      |  512k                 |
    D: 256k     |A      | C  |64k|    B      | D=256k     | 256k     |
    * See class tree example

## Segmented Memory Allocation
* Both of the paging algorithms divid a job into physically equal sized pages, which might cause serious problems in reality
    Problem: for i =1 to 100000
                        page i
    ------|-----|---------
                        page i + 1
* The idea of segemented meory allocation algorithm is to divide job into logical segments
        segement ----- subroutine
* Memory is consequently divided into page frames with different sizes -> external fragmentation reappears
* For each job we associate it with a Segment Map Table(SMT).
        | Segemnt# | Size | access right | in memory? | modified? | referenced? |
Main 20k     0        20k        X               Y                          ---> POINTER
A    10k     1        10k        X               Y                          ---> FOR THE 
B    15k     2        15k        X               N                          ---> aDDRESS

* Similar to paging we need to maintain the following data structures: Job table, segemnt map table, and memory map table
- 1. Job table lists every job in process
- 2. Segemnt Map table lists details about each segemnt
- 3. Memory map table monitors the allocation of main memory
* How to access a specific instruction? You still need to locate SEGEMENT NUMBER and DISPLACEMENT

segment size / memory location <- displacement

    external fragmentation occurs

## Segemented/Demand Paged Memory Allocation
* IDEA: Divide each segment firther into pages of equal size. Hence we need the following 4 data structures:
1. Job table lists every job in process
2. SMT (for each job) lists details about each segment
3. PMT (for each segment) monitors the pages associated with each segment
4. MMT monitors the allocation of main memory
* See class notes for visual

* Now we can move pages at will between main memory and secondary memory - **Virtual Memory**
## Advantage of Virtual Memory
    1. Job size has almost nothing to do with size of memory
    2. memory is used efficiently
    3. external frangmentation is eliminated and internal fragmentation is minimized
    4. sharing of code/data is possible
    5. Dynamic linking of program segemnts is facilitated
## Disadvantage
    1. Hardware cost is increased
    2. Overhead (for paging interrupts) is increased significantly
    3. high cost for preventing thrashing
* **End of Memory Management**. Before we say that, how does UNIX memory management work?
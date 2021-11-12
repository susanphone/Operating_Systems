## Mutual Exclusion Requirements
* Only one process at a time in critical region
* A process that halts in non-critical region must not interfere with process
* cannot delay in critical region
* when critical region is free, any other process is permitted to enter without delay
* No assumptions are made about relative process speeds
*

## Centralized Algorithm for Mutual Exclusion
* Idea: one node is control node and controls access to shared objects
* Drawback: If control node fails, can cause bottleneck

## Distributed algorithms for mutual exclusion
* nodes have equal amount of info
* node has some local info about system
    Even if global info is known to be gone, due to the communication delay, you might get the global system
* expand equal effort in making final system
* failure does not mean collapse
* no systemwide common clock for whole system
    * commuication delay, info may not be accurate

## How to handle the problem of no systemwide clock?
event a occurs before event b in different systems. 
* Problem: Communication delay
* no common clock

* Timestamp: a method that orders events in a distributed system without using system clocks
    1. each system maintains local counter
    2. when system sends a message, it increments clock and send message in form (m, T_i, i)
    3. when system receives a message, it sets it clock
    4. message x from system i and message y from system j. precedes y is Ti < Tj or Ti = Tj and i < j

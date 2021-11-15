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

* Types of messages
    1. request
    2. reply
    3. release

* Conclusion for Lamport's Solution
    * Mutex is enforced
    * algo is fair
    * deadlock free
    * starvation free
* How many meesages required? 
    * 3(N-1)    
        * N-1 request
        * N-1 reply
        * N-1 release

## Sate Diagram for Algorithm

## Improved Distributed Queue Solution
* Same as other algo only message not received in same order
* FCFS
* How messages are required? 
    * 2(N-1):
        * N-1 requests
        * N-1 replies

* A request message must be replied with a reply message
* No deadlock, why?
    * Earliest request will get all necessary replies

## A Token-Passing Approach
* Token: an entity which is held by one process at any time
* Whichever process hold the token can enter its critical region, flower game
* Algorithm:
    * Token is an array, the kth element records the timestamp of the last time the token visited Pk
    * Each process maintains an array, request, the jth element records the timestamp of the last request received from Pj.
* How many messages are required to guarentee mutex?
    * When Pi doesn't hold the token, it would broadcast the request to N-1 other processes
        * N : N-1 broadcast requests and 1 to transfer the token
    * When Pi already holds the token
        * 0 messages are needed


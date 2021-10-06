# PThread Programming Assignment
can download packages that only do 30% of the assignment is okay

* Implement a variation of Producer/Coonsumer Problem
* Buffer is doubly linked list
    * each node had a random integer value less than 50
    * initial linked list should contain 3 nodes
## Producers
* Producer 1:
    * generate a node and add to END of the list
* Producer 2:
    * generate a node and add to END of the list
* When the buffer is full, both producers should generate a message and wait
## Consumers
* Consumer 1:
    * delete from head of list the first node whose value is odd
* Consumer 2: 
    * delete from head of list the first node whose value is even
* When buffer is empty, both should generate a message and wait




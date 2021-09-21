# Deadlock Concepts
* Deadlock: a simple staircase example
    * narrow staircase, only one person could pass on the stairs at a time.
* Deadlock: a classical case of deadlock
    * four-way traffic without light or stop sign, and an accident takes up half the intersection

## Seven Examples of Deadlock in CS
1. Deadlock on file request
        p1 and p2
        p1 holds f2 and p2 holds f1
        p2 requests f1 and p1 requests p2

2. Deadlock in databases
        
            p1      p2
            p1's main goal is to change the grades
            p2's main goal is to change the address
            File
                R1: John Major
                    GPA, address
            p1: 3.5 -> 3.6
            p2: 350 student dr -> 360 university st.
* 2 people editing the same file(old project)
3. Deadlocks in device allocation
   
        p1 contains print drive
        p2 contains printer
        p3 contains plotter

        p1 requests printer
        p2 requests plotter
        p3 requests print drive

4. Deadlocks in a network
5. Deadlocks in multiple device allocations
6. 
* **See class notes**
* This scenario can collapse the whole system

## Conditions for Deadlock
* Mutual Exclusion: staircase - if it is much wider, there won't be a deadlock
* Resource Holding: p1 is holding f2 and making a request for f1, p2 is holding f1 and making a request for f2.
* No Preemption
* Circular Waiting: p1 is waiting for f1 and p2 is waiting for f2

## Modeling Deadlocks
* Directed Graph Method (Holt, 1972)
    * Holt used round nodes for processes
    * He used square nodes for resources
    * If there is an edge from square to round, then process is holding the resource
    * If there is an edge from round to square, then process is waiting for the resource

    * For the device example:
        - p1 holds tape drive, requests printer
        - p2 holds printer, requests plotter
        - p3 holds plotter, requests 
    
* A system is deadlocked if and only if there is a directed cycle
    - In a large directed graph, how do you determine there is a cycle?** 
        - When running depth first search, there is a cycle iff we encounter a **back** edge
        - Think back to 232
* Detecting cycles in a dynamic graph is not easy

            o---->o---->o---->o
                ^\-------------|
## Handling Deadlocks
* Prevention
    - prevent 1 of the 4 conditions from happening
        1. Mutual Exclusion 
            - example: a unit of CPU time can't be shared.
        2. Resource Holding
            - example: Try to satify a job's request completely. 
        3. No Preemption
            - example: Allow OS to deallocate resources from jobs.
        4. Circular Waiting
            - example: Try to force the graph to be without cycles. e.g. numering the same resources as #1, #2, #3,...

* Avoidance (Banker's Algorithm)
    1. no customer will be granted a loan exceeding the bank's total capital
    2. a customer will be given a maximum credit limit
    3. no customer will be allowed to borrow over the limit
    4. Sum of all loans $\leq$ bank's total capital
    * Example of Safe:

            Job#  Devices Allocated    Max Limit   (Remaining)
            1           0                4           4
            2           2                5           3
            3           4                8           4

        - system has 10 devices      
        - system has 4 left = **safe**
        - there is only one way out
        
    * Example of Unsafe:

          Job#  Devices Allocated    Max Limit   (Remaining)
            1           2                4           2
            2           3                5           2
            3           4                8           4
        - system has 10 devices
        - system has only 1 left = **unsafe** state $10-(2+3+4) = 1$

## Detection (CES Algorithm, by Coffman, et al, 1971)
1. Mark each process that has a row of 0's in the allocation matrix
2. $W$ <- available vector
3. Find $i$ such that process $i$ is currently unmarked and row $i$ of $Q$ is $\leq W$. If no such row exists, exit
4. If such row is found, mark process $i$ and $W \leftarrow W+ A_i$, where $A$ is the allocation matrix. Repeat step 3.
* A deadlock exists iff there are unmarked processes at the end of the algorithm
### Algorithm Example
* See handout


### Recovery
1. Stop all jobs
2. Stop any of the jobs involved in the deadlock
3. Terminate the jobs involved in the deadlock one by one, and check whether the problem is resolved.
4. Terminate a job not involved in the deadlock but with sufficient amount of resources, deallocate them to the jobs involved in the deadlock.

# Starvation
* Dining Philosophers problem (Dijsktra, 1968)
    * See slides
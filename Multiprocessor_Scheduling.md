## Multiprocessor Type
* Cluster - interconnected
    1. no shared memory
    2. each has own memory
    3. can complete tasks independently

* Special Processor - I/O processor (Master/Slave)
* tightly coupled multiprocessing
    * A PC with 4 cores
    * Hyalite System at MSU

## Granularity
frequency of synchronization between processes in a system
* up to 20 instructions
* 20 - 200 instructions
* 200-2000 incstructions
* 2000 - 1 million instructions
* independent

## Issues on Multiprocessor Scheduling
* Assignment of Processes to Processors
    1. policies
    * 1.1 static assignment
        + low overhead
        - unbalanced workload
        * Is this policy easy? use a common global queue
    * 1.2 dynamic assignment
    2. master/slave
    * 2.1 master responsible for scheduling, slave finishes jobs
        - master fails-> master performance will be decreased
    * 2.2 Peer: OS Kernel, can run and schedule 
        * OS needs to make sure that no two processors choose the same process(resource)
* Use of Multiprogramming on a Processor?
    * Coarse-grained multiprocessor: yes
    * Medium or fine: maybe not
        * example: job with 6 threads: If you move them around you will decrease system performance
* Process Dispatching
    * uniprocessing ->use priority or complicated scheduling
    * multiprocessing-> simple is better
    * from textbook
        * coefficient of variation = standard variation of service time divided by mean service time
            * round robin vs fcfs
            * srt vs fcfs
## Thread Scheduling
* threads can run concurrently within the same address space, share data
* uniprocessor-> threads can only overlap with I/O
* multiprocessor
    1. Load Sharing: use of global queue
        * FCFS
        * Smallest Number of Threads First(like shortest job next)
        * Preemptive smallest number of theads first (Shortest remaining time)
    - Disadvantage: 
        * many processors available -> the queue is shared by many processors, mutex lock/unlock could take a lot of time
        * Interrupted threads may not resume on same processor -> Local cache must be kept to handle context switching
        * Threads of one process might not run at the same time 
    2. Gang Scheduling
        * related threads run on different processors

                Setup: N processors, M jobs
                each with at most N threads

                Trivial Solution: each job gets 1/M time of N processors

                N = 4, M = 2 jobs
                3/8 = 37.55% waste


                5 total number of threads
                4 job 1, 1 job 2
                Job 1: 4/5 ( since it has 4 threads)
                Job 2: 1/5 ( since it has 1 thread)
                3 x 1/5 / 4 = 3/20 = 15% waste
                waste is idle processors
    3. Dedicated Processor Assignment
        * each program given set of processors = to # of threads
        * Many processors (a lot of resources), CPU Utilization not important
        * process(context) switching not needed
        * Example: see class notes

            System: 16 processors
            2 applications: Matrix multiplication and FFT
            Each app is implemented with 1-24 threads
            Best performance should be at 16, actually at 8
            Because of overhead



* Processor -  also called the CPU
* Process - an executeable progam, also called task, activity
* Job - a unit of work that is submitted by the user. A job is composed a set of processes
* Processor Management for a single-user system is easy: set a job either idle or busy
* Multiprogramming -  many users with many jobs on the same system
* Processor mangmnt can be further dived into two parts: 
    * Job scheduler which is at high-level
    * Process Scheduler
## Processor Scheduler
* assigns the CPU to execute the processes of those jobs placed in the READY queue by the **Job Scheduler**

            job =>HOLD--Job scheduler(for resources)-->READY--process scheduler(Algorithm--->RUN---->FINISH

        job =>HOLD---->READY----->RUN---->FINISH
                        ^--------/
                        (priority)                    
                        ^-WAIT <-/
            see class notes for better chart
* There are 2 classes of jobs:
    1. I/O Oriented
    2. CPU Oriented

* Each process in the system is represented by a data structure called **Process Control Block(PCB)**

* PCBs are usually linked into queues

        PCB:    | Process id       |
                | process status   |---> HOLD, READY, RUNNING, WAITING
                | process state    |
                | * Register counts|--> How many registers needed when 
                |                  |    job is interrupted and waiting  
                | * Main Memory    |
                | * Priority       |
                | * Process status |--> when status is HOLD, READY, and WAITING
                |        word      |         
                | Accounting       |

### What makes a good scheduling policy?
* Maximize **throughput**: running as many jobs as possible in a fixed period time.*running short jobs or jobs with no interrupt*
* Minimize **response time**: satifying interactive requests. *running only interactive job, letting batch jobs wait*
* Minimize **Turnaround time**: move entire jobs in and out of the system quickly. *running batch jobs first*
* Minimize **waiting time**: moving jobs out of READY queue as quickly as possible. *reducing the number of users*
* Maximize **CPU efficiency**: keeping CPU busy 100% of the time. *running only CPU-bound jobs*
* Ensure fairness for all jobs: giving each job an equal amount of CPU and I/O time. *disregarding priority*

* **Preemptive Scheduling Policy**: a scheduling strategy that interrupts rhe processing of a job and transfers the CPU to another job
* **Nonpreemptive scheduling policy**: A scheduling strategy that does not allow external interrupts
    



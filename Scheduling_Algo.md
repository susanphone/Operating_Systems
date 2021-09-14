# Scheduling Algorithms
## First come first serve (nonpremotive)
* the earlier the jobs arrive, the sooneer they are served
* no WAIT queue is needed (as there is no interrupt)
    A 10    B 8     C 6     D 4
    They all arrive at time 0.

    |------------|--------|--------|--------|-------->
    0           10        18       24       28

    ATT (Average turnaround time)
    10+18+24+28 / 4 = 20

    If the order is changed C->D->A->B
    |--------|--------|--------|--------|-------->
    0        6        10       20       28
    ATT: 6+10+20+28 / 4 = 16

### How you predict the running time of a job?
* Processes: P1, P2, ... , Pi, P_i+1
    Ti - exectued time for the ith process
    Si - predicted time for the ith process
* Objective: predict S_n+1 (or the new one)
    S_n+1 = 1/n * Sum(n i=1) * Ti       // Sn = 1/n-1 sum(n-1 i=1)Ti
        = 1/n T_n + 1/n(T1+T2+T3+...+T_n-1)
        = 1/n T_n + n-1 /n S_n
* In reality, more weights should be put on more recent jobs. d is delta
    S_n+1 = d(Tn) + (1-d)Sn
        = d(Tn) + (1-d)T_n-1 + ... + (1-d)^i d(T_n-1) +....+ (1-d)^n S1

    Example:
        see class notes

## Shortest Job Next (nonpreemptive)
* Does not work in an interactive system
* SJN is optimal when all the jobs are available at the same time and CPU times are estimated accurately.
    Example:
        A 10    B 8     C 6     D 4 all arrive at time 0
            D   C       B       A
        |------|----|-------|-------|----------------->
        0      4   10      18      28
        ATT: 4+10+18+28 / 4 = 15 <-----optimal

## Priority Scheduling (nonpreemptive)
1. one of the most common methods used in batch systems
2. highest priority jbos will be run first, tie is broken by arriving time
3. It us usually hard to set priorities. **Non-technical factor**: position, fee. **Technical factors**: Mmeory requirements # of peripheral devices, total CPU time, time in system(**aging**)
    too long -> aging

* Shortest Remaining Time (preemptive)
1. CPU time is divided into small fragments
2. SRT will try to finish the job closest to completetion
3. Not suitable for interactive systems
4. **Context Switching**: When a job is preempted, all its running information must be kept
    Example:
    time to run:    6       3       1       4
    arrival time:   0       1       2       3 
                    A       B       C       D            
        |------|----------|--------|---|----|------|-------|-->
        0  A   1    B     2   C    3        5  D   9  A    14
        turnaround time = completion time - arrival time
        ATT: (14-0)+(5-1)+(3-2)+(9-3) / 4 = 6.25

        SJN:
            |----------|-----|--------|--------|------->
            0   A      6  C  7  B     10    D  14
            ATT: 6 + (7-2) + (10-1) + (14-3) / 4 = 7.75

## Round Robin (preemptive) **Unix scheduling algo**
* CPU time is divied into small fragments(slices)
* Suitable for interactive systems
* first come first serve
* Slices too large -> FCFS
* Slices too small -> too much context switching
    Example:
    time to run:    8       4       9       5
    arrivale time:  0       1       2       3
                    A       B       C       D
    slice: 4 microseconds           
                       A    B     C     D     A     C    D    C
                    |----|-----|-----|-----|-----|-----|---||---|>
                    0    4     8     12    16   20     24  25   26
        ATT: 20 + (8-1) + (26-2) + (25-3) / 4 = 18.25ms

## Highest Response Ratio Next (Nonpreemptive)
* Objective: run jobs to minimize (turnaround_time/service_time)-ratio
* As both turnaround time and serivce time cannot be known in advance in most istuations, we approximate them based on past history (especially when the job takes several slices to run)
* Approximate ratio R
**see class notes to finish slides**




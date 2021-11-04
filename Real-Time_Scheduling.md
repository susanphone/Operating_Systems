# Real-Time Scheduling
## Examples
* requires correctness of logical computation and timing
* Examples:
    * Aircraft control
    * Cruise missile
    * Process control plants (manufacturing)
    * Robotics
## Basic Concepts
* Hard real-time task: meets its deadline, or fatal error will occur
    * Missile
* Soft real-time task: try to meet deadline, schedule even after deadline passed
* Aperiodic task: random tasks
* Periodic task: a sequence of tasks once per period time T

## Characteristics of real-time OS
* Determinism
    * Multi-process in gen non-deterministic
        * Many jobs fight for resources, you might have to break a tie randomly
    * respond by external events/timing, determResponsiveness: 
        * Time to start interrupt
        * Time to finish interrupt
        * Is nested interrupt? B interrupts A is C allowed to interrupt B?
* User Control
    * processed immediately
* Reliability
    * error not recoverable
* Fail-soft Operation
    * some soft tasks allow for failure
    * preserve capacity and data
    * correct problem, min effects
    * Stability: impossible to meet all deadlines, prioritize critical tasks

## Features of modern real-time OS
* Fast process/thread switch
* small
* quick response
* preemptive scheduling based on priority
* Primitives to delay tasks for limited time
* Special alarms and time-outs
#### important: start and end hard tasks by their deadline

## Deadline Scheduling
* Ready time: task ready to run
* Starting deadline: task must start
* Completion deadline
* Processing time
* Resource requirement
* Priority

* Scheduling with earliest deadline gives optimal solution

## Rate Monotone Scheduling
* period T
* rate 1/T
* Computation Time C
* C <= T
* Utilization is C/T
* RMS ranks tasks shortest period as highest priority
* n tasks, each with fixed period and execution time

* RMS is popular in practice because:
    1. performance difference is small
    2. can handle a mix of hard real-time and soft real-time tasks
    3. stability

### Example:
    P1: C1 = 20, T1 = 100 U1 = 0.2
    P2: C2 = 40  T2 = 150 U2 = 0.267
    P3: C3 = 100 T3 = 350 U3 = 0.286

    U1 + U2 + U3 = 0.753 <= 2 * (2 ^ 1/3 -1) = 0.779 


    |---C1---|-----C2-----|-----C3------|---cC1---|----C3----|---cC2---|--C3---|--->
    0        20           60           100       120        150       190     200

    -->|---c2C1---|---C3--|------IDL------|---cC1---|---cC2---|
      200        220     240             300       320       350
                                                             ?^-Second copy of P3

# Queueing Analysis
## Why Queueing Analysis
* If system environment changes(users double), evaluate the resulting system performance
    1. Do an after-the-fact analysis
    2. Make a simple projection(estimation)
    3. Do a queueing analysis
    4. Program and run a simulation model (can be expensive)
* Exponential and Poisson Distributions
    * If the standard deviation is roughly 0 -> most jobs have the same service time

## Basic Concepts - Single Server Case
* $\lambda$ : arrival rate
* $w$ : average number of waiting jobs
* $T_w$ : mean time a job must wait
* $T_s$ : mean service time
* $r$ : avg number of jobs
* $T_r$ : mean residence time
* $\rho$ : fraction of time the server is busy
* Queueing System Stucture and Parameters for Single-Server Queueing
* Using handout to calculate each portion

## Applications for Signle-Server System
* LAN with 100 PCs. avg query time 0.6. standard deviation(assumption 2) is equal to the mean. the query rate over LAN reaches 20 per minutes.
    1. What is the avg response time? resting time
        * compute $\rho$ = 20 arrivals per minute \times 0.6s per query
        * compute $T_r = T_s/ 1-\rho$
    2. If 1.5 response time is the acceptable maximum, what is the maximum of message load?
        * rephrase the question as we want 90% of all responses to be less than 1.5s
            * $m_{T_r}
    3. If 20% more utilization is experienced, what will be the corresponding response time?
        * Compute Old T_r
        * Compute New T_r
* LAN connected to internet with a router. Packets arrive with mean arrival rate of 5 per second. avg packet length is 144 bytes and exponentially distributed. Line speed from router to Internet is 9600bps
    1. What is the mean residence time in the router?
        * Compute $T_r = T_s / 1-\rho$
    2. What is the avg number of packets in the router?
        * Compute $r = \rho / 1 - \rho$
    3. What is the upper bound of the number of packets in the router, for 90% of the time?
        * Compute probability of r is n
        * Compute probability that r is bounded by n


    
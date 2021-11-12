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


## Basic Concepts - Mutliserver Case
* Single server cases carry over
* N : number of servers
* \rho: utilization of each sevrer
* u = N \times \rho: utilization of whole system
* \lambda \leq N/T_s
* divide arrival jobs $\lamba / N$
* Assumptions: **(Not going to be on the test)**
    * Poisson distribution
    * Erland-C function
    * r
    * w
    * T_r
    * T_w
    * M_T_w(y)

## Applications for multi-server system
5 processors, T_s = 0.1s. Standard deviation T_s, \sigma_T_s is 0.094s. jobs arrive at rate of 40 per second
1. What is the avg response time?
    * When a common queue is used, Tr is reduced by a factor of 3
2. What is the avg waiting time?
    * reduced by a factor of 7
3. What it the avg (max) waiting time for 90% of the time?
    * reduced by a factor of 3

## Distributed Queue Solution
* Assumption
    1. N nodes
    2. messages received in logical order using the time stamp
    3. all messages delivered in finite time enforced with TCP/IP
    4. node can send message to all other nodes
    5. Each node keeps an array q, each node has 1 resource
* Sites have a copy of common queue
* before decision, must receive message from other sites
    * Why? otherwise you can't enfore 2
* Three types of messages
    1. request to access a resource at time Ti
    2. reply grants access to a resource
    3. release a resource previously allocated (finished using it)

* Algorithm
* COnclusion for Lamport's Solution
    1. mutex is enforced
    2. algorithm is fair, requests are granted accordingly
    3. deadlock free because time stamp is consistent at all sites
    4. starvation free, once Pj exits critical region, it releases the resource (with a release message), which deletes Pj's previous request
* To guarentee mutex, how many messages are required?

    * From the algorithm, N-1 requests message 
    * when can you access it, N-1 reply message
    * N-1 release message
    therefore => 3(N-1) messages are required

## Some Famous Distributed ALgorithms
* Leadership Election:
    * leadership can switch easily
    1. each process has a unique ID known to all members
    2. leader, highest ID
    3. can fail at any time
* Bully algorithm
    1. send periodic message saying they still kickin
    2. every 50-75 CPU cycles send elect message with higher ID
    3. otherwise is then is a reply, P exits
    4. If no reply, P wins, then sends coordinator message to all process, they leader
    5. elect message, reply message to sender

* Example:
    * 5 is the leader
    * 2 notice didn't get message from 5, so election time
    * 2 tries to be leader, 4 and 3 reply, 2 exits
    * only 2 knows 5 is dead, 3 and 4 does know
    * four will be leader
    * 4 sends message saying they are the leader
* how do you know they crash, by periodic messages, if the leader doesn't send a message in the period, they are assumed dead.
* drawback -  number of messages -> O(n^2) messages (that's too many)
* Robust algo, only works when set is small

* Ring Based Algorithm
    1. coodinator send messages, so if not working
    2. P sends elect Message
    3. nodes receive elect message, if no receiver id, add and pass on the message. If there is a receiver id, send message (coordinator is the highest)

* Example:
    * node form an initial ring
    * everybody knows the structure of the ring
    * if a node fails, no recoginition that is was sent to five. 
    * message has reached 2,3,4,1.
    * coordinator sends a message naming the leader as the highest node
    * 2 sends the initial alert

* Monday cover two more algorithms
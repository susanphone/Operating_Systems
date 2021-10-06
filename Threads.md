# Treads
* Use the handout packet that was given

* Mimic something we try to do for process for producer consumer problem
## example 1
    prod.c
    producer         consumer
        -> |_|_|_|_|_|  ->
    if you reach overflow that producer will die
    if you reach underflow the consumer wil die

* fork: creates a new process
* the main function automatically gives you PID = 0

## example 2
    prod1.c
    multiple producers
        producer 1 creates 2
        producer 2 creates 5
        consumer takes 1
* two forks
    * pid and pid1
* no cooperation between the two producers

## PThread
* was not originally in the UNIX system
* created and edited later in the 80s

        ttt.c 
        use the packet
        tid1 = pthread_create command to create producer 1
        tid2 = pthread_create command to create producer 2
        one process to make the producers work together
        producer         consumer
                    M
            -> |_|_|_|_|_|  ->
               _|_|_|_|_|_
                    N
* command has to be ```cc -pthread ttt.c``` where ttt.c is the file
* did not change the M until N overflow
    * first run N increases by one 
    * once N hits overflow, N remains in its final count and M increases by 1





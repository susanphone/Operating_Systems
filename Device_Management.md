# Device Management
## Basic Concepts
* Manages every peripheral device in the system
    * Think Printer,  equipt with a queue
    * Status of each device
    * Which process gets device and how long(sharing disk drive)
    * Allocate and Deallocate devices
* System Devices
    * only 1 job at a time(tape driver, printer)
    * shared devices
    * virtual devices

* Storage Media
    * Sequential access, on after the other
    * Direct access
* Types: human readable(printer), machine readable(disk drives), and communcation(communicating with modem)

## Sequential Access Storage Media
* **Paper**: printouts -> already outdated
* **Magnetic Tape**: archiving
    * half inch tape with tracks
        * example: 8 tracks for data, with another parity track
            * This can only check whether some data is corrupted. *Correction will be covered later*
            * RAID
* Blocking: alt way to group records into blocks before recording them on tape

        |record1| IRG | -----> Blocking : |r1|r2|r3|r4|r5|IRG|
        inter record gap, about 1/4 or 1/2 inch
    * + i/o more efficient, waste less tape
    * - overhead, wasted buffer space

## Direct (random)Access Storage Devices
* Devices:
    * fixed read/write heads
    * movable read/write heads
* Fixed-head drums/disks
    * one head per track
* Movable-head drums/disks
    * one head, can move
* Optical Disk Storage(CD-ROM)
* Access Time:
    * Seek time
        * Physical, slow
    * search time (rotational delay)
        * rotate drum or disk
    * transfer time
        * transfer data to main memory
* Access Time for fixed-head devices
    * Access Time = Search Time + Transfer Time
    * Example:

            setup: 10 records, 100 bytes each
                avg search time(rotational delay): 8.4ms
                transfer rate: 0.00094ms per byte

            No blocking: for one record, 
                access time = 8.4 + 100 * 0.00094
                = 8.4 + 0.094 (for 1 record) = 8.494

                For 10 records: 10 x 8.494 = 84.94

            With Blocking: 
                8.4 + (0.00094 x 100) x 10
                = 9.34 (with 10 records blocked in one)
* Access Time for Movable Head Devices
    * Access Time = Seek Time + Search Time + Transfer Time

            10 record, 100 bytes each
            Avg Seek time: 25
            Avg Search time: 8.4
            transfer time: 0.00094

            Without Blocking:
                1 record = 25+8.4+ 0.00094 = 33.494
                10 records = 10 * 33.494 = 334.94 ms 
            With Blocking:
                25 + 8.4 + (0.00094) * 10
                = 33.4 + 0.94
                = 34.34 for 10 records
## Disk Scheduling Algorithms
* Objective: minimize arm movement, mean response time, the variance in response time
    * half mechanical, half electronic

## Device Handler Seek Strategies
* First Come First Serve(FCFS)

        setup: 0------------------------------------40(closest to center)

        head at track 15, requests: 4, 37, 11, 35, 7, 14
        15->4->37->11->35->7->14 
        total # of tracks visited: 
            (15 - 4) + 37-4 + 37-11 + 35-11 + 35-11 + 14-7
            = 129 tracks
* Shortest Seek Time First(SSTF): the request at the track closest to the one being served is the next
                
        setup: 0------------------------------------40(closest to center)

        head at track 15, requests: 4, 37, 11, 35, 7, 14
        15->14->11->7->4->35->37

        total # of tracks visited: 
            (15-14) + 3 + 4 + 3 + 31 + 2 = 44
            or 15-4 + 37-4 = 44
    * Drawback: Access a narrow interval for a long time is not good, Mechanically things need to keep running
* SCAN -  almost like round-robin
    * most widely used

        go between 0 and 40, serve request on the way
        setup: 0----------15->--------------------------40(closest to center)

        head at track 15, requests: 4, 37, 11, 35, 7, 14

        15 -> 35 -> 37 -> 40 -> 14 -> 11 -> 7 -> 4
        total # of tracks visited: 25 + (40-4)
            = 25 + 36 = 61
    * Question: Now, if we have a request at 10, what do we do?
        - 4 -> 0 -> 10 i.e. need to add up to 14(not 6)
* LOOK- similar to SCAN, but won't go all the way to track 0 or the highest track unless requested

        setup: 0------------15->------------------------40(closest to center)

        head at track 15, requests: 4, 37, 11, 35, 7, 14

        15->35->37->14->11->7->4
        if the next one is 10, then
            4->10
* C-SCAN -  similar to SCAN but only when the head moves to center is the request serves

        setup: 0----------15->--------------------------40(closest to center)

        head at track 15, requests: 4, 37, 11, 35, 7, 14
        15-> 35->37->40->0->4->7->11->14
        total number of tracks visited: 20 +(40-35) + 40 + 4 + 3 + 4 + 3 = 79
    * Minimizes the variance of the response time
        * if 4 7 11 14, the difference between 4 and 14--> relatively closer 
    * C-SCAN is used a lot
* C-LOOK -  similat to LOOK but only when the head moves toward center is the request served

        setup: 0-------------15->-----------------------40(closest to center)

        head at track 15, requests: 4, 37, 11, 35, 7, 14
        15->37->35->4->7->11->14
        total number of tracks: 20+2+33+3+4+3 = 65

        WHat would happen is you add track 10?

* N-Step-SCAN and FSCAN
    * Arm Stiffness: Motivation -  with SSTF, LOOK, and C-LOOK, it is possible that the arm may not move for a long time (over some interval). Not being able to move and you become sore

            setup: 0________10--------20_______________________40(closest to center)

        head at track 15, requests: 10 to 20 and there ar 500,00 requests
    * N-Step-SCAN: it segments the disk request queue into subqueues of length N. 
        *The Subqueues are processed one at a time, using SCAN
        * If N-> Large, N-Step-SCAN -> SCAN
        * If N-> Small, N-Step_SCAN -> FCFS
    * FSCAN: only uses 2 subqueues
        * When a scan begins, all the requests are put in a queue.
        * During the scan serving the requests in the current queue, all new requests are put in the second queue. **Double Buffering**
## I/O Buffering Schemes
    * No Buffering
    * Single Buffering - in and out the same buffer
    * Double Buffering - in one buffer, out the other buffer
        * Most widely used buffer, convenient and suitable
    * Circular Buffering - round robin style, you shouldn't need this many buffers
## RAID: recover from errors

## Search Strategies: Rotational Ordering
* Once the read/write head has been positioned (on some specific track), reorder the requests to optimize the **search time**.
### Example:
* Setup
    * five sectors 0 to 4
    * five tracks 0 to 4
    * read/write point
* Time
    * seek time - 5ms from track i to i+1
    * search time - 1ms from sector j to j+1
    * transfer time - 1ms
* Requests
    * head is initially (0,0)

                Track | Sector
                  0   |  1
                  1   |  3
                  2   |  0
                  2   |  3
                  2   |  4
                  3   |  2   
                  3   |  0

* Without Rotational Ordering

        requests    seektime    searchtime      transfer time
        (0,1)           0           1               1
        (1,4)           5           2               1
        (1,3)           0           1               1
        (2,0)           5           2               1
        (2,3)           0           2               1
        (2,4)           0           1               1
        (3,2)           5           2               1
        (3,0)           0           2               1

                        15          13              8(+ = 36)

* With Rotational Ordering

       requests  search time
        0,1         1
        1,3         2
        1,4         1
        2,4         0
        2,3         1
        2,0         2
        3,0         0  
        3,2         2

                    9 (save 4ms)

## RAID ( Redundant Array of Independent Disks)
* Motivation and Key idea
    * I/O -> speed limited
    * use multiple smaller disks instead of one big disk
    * the more agents, the high chance of errors
    * distribute data for simultaneous access
    * correct mistakes by increasing I/O performance

* sketch of data mappign for RAID
    * 1 disk to 4 smaller disks
        * chance of mistakes increases
    * RAID(0) - redundant
    * RAID(1) - copy for all four disks
        * but this wastes resources
        * like having four spare tires in the car
    * RAID(2) - Hamming Code
    * RAID(3) - bit-interleaved parity
        * fifth disks
    * RAID(4) - block level parity
    * RAID(5) - block level distributed parity
        * all drives have some part of parity
    * RAID(6) - 2 parity drives 

### RAID 3: 
1. It uses a parallel access technique
2. It only requires a single redundant disk
* Example: $X_0, X_1, X_2, X_3-----X_4$ disk drives for data
    * $X_4$ ---- parity disk
    * At the ith bit we have
        * $X_4(i) = X_3(i) + X_2(i) + X_1(i) + X_0(i)$
            * + --- addition with no carry or exclusive OR
    * If $X_1$ fails, add $X_1(i) + X_4(i) at both sides
        * x4 _ x1 + x4 = X_3(i) + X_2(i) + X_1(i) + X_0(i) + x1 + x4
            * remove x4 = remove x1
            * X_1(i) = x4 + x3 + x2 + x0
        * X_1 is recovered

                1 + 1 = 0
                0 + 0 = 0
                1 + 0 = 1
                0 + 1 = 1
### RAID 4:
* Not commercially implemented, but its algorithm is used in RAID 5, and RAID 6
* Example:

        x0, x1, x2, x3 --- data disks
        x4 --- parity disk
        suppose a write(change) occurs at x1, for each bit i 
        updated parity x4'(i) = x3(i) + x2(i) + x1'(i) + x0(i)
                use 3 reads(x0, x2, x3) and two writes(x1', x4')
        = x3(i) + x2(i) + x1'(i) + x0(i)
            + x1(i) + x1(i)
        => x3(i) + x2(i) + x1(I) + x0(i) = x4(i) + x1(i) + x1'(i)
            2 reads and 2 writes
        
### PCB Word: Stores some running info (like register contents)
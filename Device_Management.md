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
                

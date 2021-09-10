# Memory Hierarchy
* The design constraints of memory rest on:
    1. Capacity
    2. Speed (access time)
    3. Cost (unit cost)
* Their relationship
    * Faster Speed (access time) -> Greater Cost
        A->B <-> ~B -> ~A
        smallerCost -> slower speed
    * Greater Capacity -> smaller cost
    * From these two we have: Greater Capacity -> Slower Speed
    * Cannot have Greater Capacity, Smaller Cost, and Fast Speed at the same time!
## Memory Hierarchy Pyramid
    see class notesz
* Based on the pyramid:
    * Cost is decreasing
    * Memory cap is increasing
    * Speed is slowing down
    * Frequency of access of memory by processor is decreasing
* Why?
    * **Locality of Reference**
        * Not only valid in OS.
            * Basis for compiler optimization, databade management, internet browsing, and 
    * See level of memory example
        Level 1 memory (M1) : 1000 words, 0.1 us access time
        Level 2 memory (M2) : 100,000 words, 1 us access time
        T1 - access time for M1 (e.g. cache, disk cache)
        t2 - access time for M2 (e.g. main memory)
        T - access time for the whole system
        H - Hit ratio, the probability that you can find an item in M1
                    T = H * T1 + (1 - H)
                    = H * T1 + T1 + T2 - H * T1 - H * T2
                    = T1 + T2 - HT2
                    = T1 + (1-H) + T2
    * Cache/Main Memory Stucture example
        CPU -> Cache            Word Transfer
        Cache <- Main Memory    Block transfer (-> page)
## Cache Memory
* Motivation
    see class notes
* This fast memory, almost *invisible* from OS, is **cache**
* The objective of cache memory is to speed up the memory so that it is almost as fast as the speed of processor and at the same time it provides a memory size which is large enough (for most jobs).
* Let's us look at the structure of cache/memory
    * see read address example
        * What problems can you see with the example?
            * something must be moved out of the cache to load the block containing RA into the cache
* Cache design is beyond this course,  but the following must be considered in general
    1. Cache size
    2. Block size. Suitable size block = high hit ratio
    3. Mapping function. When a block is read into cache the 1st question should be where should we put it? 
            * when one is read in, another should move out
            * the more flexible the mapping function, the more time it takes to search in the cache
        * this is hash functions without chaining
    4. The replacement policy 
        * FIFO
    5. Write policy. If the contents of the block in the cache is changes, we should write back to the main memory.
        * When should this happen?
            right away or 10 CPU cycles
* Example *Performance Analysis of Two-Level Memory*
    * We want this ratio to be close to 1
    * T2/T1 -> constant
* Example *Access Efficiency as a Function of Hit Ratio (r = T2/T1)*

* The average cost per bit for two level memory, *C_s*

        C1 = C1S1 + C2S2 / S1 + S2

* To make *C_s* roughly the same as *C_2*. We should make *S1* << S2. (C1>>C2 due to the hardware cost which we can do very little to change it). 
    See class notes for equation
    * Example Relationship of avg memory cost to relative ememory size for a 2 level memory
* Example hti ratio as a fucntion of relative memory size
    * In Practice:
        1. Cache size: 1K ~ 128K
        2. Hit ratio > 0.75 almost all the time :)
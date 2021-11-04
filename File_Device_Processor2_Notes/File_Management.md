# File Management
## Basic Concepts
* file manager controls all files in the system
* several factor determine efficiency of file manager:
    1. organized
        * FAT (file allocation table)
    2. storage
    3. record structure
* creating, deleting or modifying a file means file manager is functioning
* Responsibilities of a file manager:
    1. keep track of where each file is stored
    2. Allocate each file with an access right and record its use
    3. Deallocate a file when it is deleted
    4. Maintain available storage space for future use
* Some basic definitions
    1. a field: a cell
    2. a record: a line
    3. a file: a group of records

            | stu no | name | GPA | address |
            |  34    | me   | 3.5 | 101 str |

            field: me
            record: the line
            file: a group of records
## File Organization
* Record format:
    * fixed: if size too small, truncate the field. If size too big spaces are wasted
    * variable: does not truncate, does not waste
* Physical File Organization:
    * decided by way records are arranged
    * what kind of medium is used to store files
        * tape vs disk
* PFO composed of:
    * sequential record organization
    * Direct record organization
    * indexed sequential record organization
        * think of the index at the end of a textbook
* Way to store the data, look at the parameters:
    * Volatility of data
    * Activity of the file
    * Size of the file
    * Response time
* Sequential record Organization:
    * stored and retrieved sequentially
    * optimization version
* Direct Record Organization:
    * id by relative address
    * key, use hashing technique
    * collision not avoidable
* Indexed sequential record organization:
    * think b tree(height usually small), created and maintained through indexed sequential access method
    * overhead is a drawback

## Physical Storage Allocation
* Contiguous Storage: records are stored one by one
    * like a tape
* Advantage: starting sequentially
* Disavantage: cannot expand file
    * you would have to push all the records away
    * each explansion takes $n$ time


* Noncontiguous Storage
    * cells all the same size, at the end of each cell is a pointer
    * linking takes place at the storage level, minor changes possible
        * linking takes place at directory level

* Indexed Storage:
    * direct record access
    * one block has all information about the file, no use for pointers

## Data Compression
* abbreviate records with repeated characters
    * Adambbbb -> Adam4b
    * 300,000,000 -> 3#8 - mean 8 zeros
* repeated terms can be compressed 
    * Grade Point Average -> GPA
    * Bachelor of Arts -> BA
* front-end compression, used in database for index compression
    * most interesting compression, compressing indices
    
            original list     compressed list
            Jack, Betty         Jack, Betty      
            Jackson, John       4son, John
            Jackson, Peter      8Peter
            Jacksonn, Peter     7n, Peter
    * find the letters that are the same
    jack and jackson
    jackson and jacksonn

## Access Method
* determined by file organization:
    * indexed sequential file, most flexible
    * sequential file, least flexible
* uses **CBA (current byte address)**, address of the last byte to access nect record

* Sequential access(fixed length records)
    * current CBA = previous CBA + record length (r2 = r1) + record length)
* Sequential access(variable length records)
    * $CBA_k = CBA_{k-1} + RL_k + N$
    * RL is record length
    * N is space used for storing length
    * |RL1 | data for r1| RL2 | Data for r2|
        * RL1 is storage length of r1
* Direct Access (Fixed length records)
    * CBA = record number - 1 * RL
* Direct Access (Variable length records)
    * Hard, sequential search is a trivial solution
    * Augmented list 
        * example: skip list

## Access Control
* in 1950s access control never a problem for FORTRAN users
* now, five things to do on a file
* four ways to do access control
    1. Access Control Matrix
        * table of files and users RWED or RW-- or R-E- or RW-D
    2. Access Control list
        * each file is entered in the list and contain names of the users who are allowed to access with the proper access rights
        
                File    Access
                file1   user1(RWED), user2(R-E-)
                file2   user1(RW--), ...
    3. Capacity List
        * List every user and the files they can access

                User    Access
                user1   file1(RWED), file2(RW--), ...
    4. Lockword
        * almost like password
        
## File Organization
* Indexed File: updated infrequently and accessed frequently in random order
* Indexed Sequential File: update frequently and accessed in its entirety relatively frequently
* Sequential File: stored and retrieved in order
* Hashing File:
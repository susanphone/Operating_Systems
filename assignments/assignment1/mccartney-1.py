# Susan McCartney
# CSCI 460: Assignment 1
# September 22, 2021

# Memory management
class Memory():
    pages = [[] for _ in range(16)]
    jobHistory = []

    def __init__(self):
        for i in range(16):
            self.pages[i] = [0] * 4096

    # adds a new job to memory
    def addJob(self, jobId, size):
        # keeps track of job history to remove the job that went first
        self.jobHistory.append(jobId)
        bytesAllocated = 0
        # Iterate through the memory and put the job in unallocated memoru
        for i in range(16):
            # in range of bytes
            for j in range(4096):
                # stop adding bytes to memory once the job size has been reached
                if bytesAllocated == size:
                    return
                if self.pages[i][j] == 0:
                    self.pages[i][j] = jobId
                    bytesAllocated += 1

        # If the memory is full, remove the job that arrived first
        if bytesAllocated != size:
            remainingBytes = size - bytesAllocated
            freedBytes = 0
            # keep freeing the oldest job first until there is enough
            # unallocated memory to finish storing the job
            while (freedBytes < remainingBytes):
                oldestJobId = self.jobHistory.pop(0)
                freedBytes += self.removeJob(oldestJobId)
            self.addJob(jobId, remainingBytes)

    # removes job from memory, returns the number of bytes that were freed
    def removeJob(self, jobId):
        bytesFreed = 0
        for i in range(16):
            for j in range(4096):
                # if the byte is the job id, free the byte
                if self.pages[i][j] == jobId:
                    self.pages[i][j] = 0
                    bytesFreed += 1
        return bytesFreed

    # print out memory
    def printMemory(self):
        unallocated = 16 * 4096
        curJobNum = 0
        numCurJob = 0
        jobPages = 0

        # Iterate through all the memory
        for i in range(16):
            jobPages += 1
            for j in range(4096):
                curByte = self.pages[i][j]
                # on the first byte, initialize the first job
                if i == 0 and j == 0:
                    curJobNum = curByte
                    numCurJob = 1
                    if curByte != 0:
                        unallocated -= 1
                    continue

                # If the current byte is part of this job,
                # increment the size, and decrecement the unallocated memory
                if curByte == curJobNum:
                    numCurJob += 1
                    if curByte != 0:
                        unallocated -= 1
                else:
                    if curJobNum != 0:
                        print("Page: %d-%d Job: %d Size: %d\n" %
                              ((i-jobPages)+2, i+1, curJobNum, numCurJob))
                    else:
                        print("Page: %d-%d UNALLOCATED Size: %d\n" %
                              ((i-jobPages)+2, i+1, numCurJob))

                    curJobNum = curByte
                    numCurJob = 1
                    jobPages = 1
                    if curByte != 0:
                        unallocated -= 1

        if curJobNum != 0:
            print("Page: %d-%d Job: %d Size: %d\n" %
                  ((16-jobPages)+1, 16, curJobNum, numCurJob))
        else:
            print("Page: %d-%d Total unallocated: %d\n" %
                  ((16-jobPages)+1, 16, unallocated))


def main():
    # Create a memory
    memory = Memory()

    # Loop for user input
    while True:
        inp = input(">")
        if inp == "exit":
            print("Goodbye")
            return
        if inp == "print":
            memory.printMemory()
            continue
        if inp == "":
            continue
        # split input into job id and byte size
        splitInput = inp.split(" ")
        jobId = int(splitInput[0])
        size = int(splitInput[1])
        if size == 0:
            memory.removeJob(jobId)
        else:
            memory.addJob(jobId, size)


main()

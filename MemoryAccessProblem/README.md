# Find memory conflicts among multiple threads
Original Problem: http://www.geeksforgeeks.org/find-memory-conflicts-among-multiple-threads/

Consider a RAM organized in blocks. There are multiple processes running on the system. Every application gets below information.

(Thread T, Memory Block M, time t, R/W) which essentially tells that the thread T was using memory block M at time t and operation could be read or write.

Memory conflict is defined as –
– Multiple read operations at the same location are not cause of conflict.
– One write operation between x+5 to x-5 to location M, will be cause of conflict for a thread accessing location M at time x where x is some time in standard unit of time measurement.
– Example – If thread T1 accessed memory location M at time x+1 and if a thread T2 accesses location M before time x+6, then T1 and T2 are candidate of conflict given one of them does write operation.

You are given with the list of threads accessing memory locations, you have to find all conflicts.
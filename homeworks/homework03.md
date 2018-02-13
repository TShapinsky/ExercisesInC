## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?
6 bits, if there were one less letter it would be 5 bits.
2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?
4294967296
3) What is the difference between "memory" and "storage" as defined in *Think OS*?
Memory is fast volatile address space. Storage is a slow non-volatile address space.
4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?
GiB is 2^30 bytes GB is 10^9 bytes
5) How does the virtual memory system help isolate processes from each other?
Even if two processes try to access the same place in virtual memory they may be mapped to different places in physical memory.
6) Why do you think the stack and the heap are usually located at opposite ends of the address space?
Because both grow so the most effecient use of the address space is to have a large amount of space in between that either can grow into.
7) What Python data structure would you use to represent a sparse array?
A dictionary because you can have two values at indices and nothing inbetween, though I suspect a python dictionary may function like a hashmap.
8) What is a context switch?
When the OS pauses a process by saving it's state and switching to a different process requiring the page table information in the MMU to be replaced

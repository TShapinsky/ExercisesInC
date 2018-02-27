## Homework 4

### C Exercises

Modify the link below so it points to the `ex04` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

Files seem like something which should be contiguous but in actuality files (inodes) can be very fragmented.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

File name, mode, inode structure, pointer to current position.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Loading an entire block as opposed to a single byte from the disk. Prefetching blocks that the OS thinks will be useful later. Using memory as a buffer for disk. Caching the disk in memory.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  

Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

The file was buffered in memory but never flushed to the disk.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

FAT is simpler in that is is just pretty much a linked list. UNIX inodes allow you to randomly seek through a file.

6) What is overhead?  What is fragmentation?
Overhead is space taken up by a filesystem that is required for it to work, but does not contain any data 

for the user. Fragmentation is when a file's parts are non-contiguous.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The "everything is a file" principle is good for many things because it allows the same api to be used for many things cutting down on complexity. It could be bad for certain things because it adds overhead to the system, things that are very high bandwidth may not work well as files.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



There are no reading questions from Think OS for this homework.

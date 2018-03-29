## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

`malloc` should take constant time. `calloc` should take time proportional to the size of the allocated chunk because it zero initializes.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

Could trigger a segmentation fault

b) Writing to unallocated memory.

May trigger seg fault when read from in the future which could be very confusing to debug. There's also a chance you could write into memory being used for data structures other useful stuff. 

c) Reading from a freed chunk.

This is the same as reading from an unallocated chunk, can result in a a seg fault.

d) Writing to a freed chunk.

This is the same as writing to an unallocated chunk.

e) Failing to free a chunk that is no longer needed.

This would result in a memory leak.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)

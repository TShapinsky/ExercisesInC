## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

This is called a jump and when it happens the program starts executing from the the new value of the program counter. 

2) What is the fundamental problem caches are meant to solve?

Caches are meant to solve the problem of memory being too slow to keep the CPU running at 100%.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

50% -> 1*.5 + 10*.5 = 5.5ns

90% -> 1*.9 + 10*.1 = 1.9ns

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

When using an array of struct pointers the pointers would be cached but everytime you want to access the values of a struct you have to go out to memory. This is in contrast to an array of primitives where the values would be cached as the array was traversed.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

No, "cache aware" algorithms are written to perform best with certain cache parameters so simply increasing locality, while it could increase performance, would not be "cache aware".

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

intel i7-7300U 4 cores 2.6GHz 3MB cache = $281

intel i7-7500U 4 cores 2.7GHz 4MB cache = $393

1MB = $112

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

The memory at the bottom of the hierarchy is small and fast so badly designed cache policies could have large negative effects on performance. 

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

pause all processes and present the user with a dialog to kill a process before continuing.


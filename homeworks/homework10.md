## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

Concurrent modification of the data structure will not result in the data becoming wrong or the data structure being corrupted.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

If the buffer was full and the size was `n` then it would have the read and write pointers in the same place meaning that there would be no way to distinguish between full and empty.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

If two threads tried to add an element at the same time they could both assign values to the same entry before incrementing the write pointer twice.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

`cond_wait` locks the mutex. So if the mutex was already locked the function would hang.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

we know the condition was true at some point. We think the condition is probably still true.

6) What happens if you signal a condition variable when there are no waiting threads?

There is no effect.

7) Do you have to lock the mutex to signal a condition variable?

No, signalling a conditional variable does not require a mutex.

8) Does the condition have to be true when you signal a condition variable?

The condition is defined by when you signal the variable, so by definition, yes.

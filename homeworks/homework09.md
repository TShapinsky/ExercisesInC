## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

Each thread can add stack frames and variables so having a shared stack just wouldn't work.

2) What does the gcc flag `-lpthread` do?

It includes the pthread library when compiling.

3) What does the argument of `pthread_exit` do?

The argument of `pthread_exit` is the mecanism by which you can give a return value when exiting a thread.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

The man page for `pthread_join` states that `All of the threads in a process are peers: any thread can join with any other thread in the process.` so it would make sense that this join would complete successfully.

5) What goes wrong if several threads try to increment a shared integer at the same time?

Since the read and write are seperate steps it is conceivable that all threads would read the value before any of them write. This would result in an increment of one instead of one per thread.

6) What does it mean to "lock a mutex"?

once a thread calls `pthread_mutex_lock` anyother thread that calls the function will wait until `pthread_mutex_unlock` is called.

## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?
A program like docker which allows the user to run a different self contained operating system ontop of an existing one.
2. What is the difference between a program and a process?
A process is a container through which a program is used by an operating system.
3. What is the primary purpose of the process abstraction? 
To make it so you don't have to write everything from the ground up everytime you want to start a new program.
4. What illusion does the process abstraction create?
That high level abstractions can be used without accruing large amounts of overhead.
5. What is the kernel?
The kernel is a piece of software which handles interactions with hardware and low level things like system calls.
6. What is a daemon?
A daemon is a process which runs in the background which can add services to the operating system. Like providing an interface to use printers and/or email.

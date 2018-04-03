## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

To handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The hardware is responsible for saving the program counter so that after the interrupt is over it can pick up where it left off.

3) What is the difference between an interrupt and a context switch?

A context switch is a behaviour that can happen during an interrupt where instead of returning to the interrupted process the kernel switches to a different process.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

A disk read may complete giving the process data to continue running.

5) Why might a scheduler want to give higher priority to an I/O bound process?

I/O bound processes will spend a good portion of their time blocked so by favoring them you can get the requests out faster and run CPU-bound processes while they are waiting for a response.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

place 8 pieces on the griddle. After 5 minutes replace four with the remaining four uncooked pieces and flip the four remaining on the griddle. After 5 more minutes remove the four pieces that are done and replace them with the four that you took off in the last batch. After a final five minutes the final eight pieces of french toast will be done.

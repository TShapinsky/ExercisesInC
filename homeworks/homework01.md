## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.
Interpereted languages 
2) Name two advantages of static typing over dynamic typing.
Static typing allows type errors to be found in compile time. Static typing can also (in my opinion) create more readable code. For example given a function with the definition `void setColor(int color)` it can be intuited that the function takes an integer of the form `0xRRGGBBAA` whereas from a definition with the form `setColor(color)` it is impossible to intuit the type of argument the function takes.  

3) Give an example of a static semantic error.
```C
	void doSomethingCool(int x, char * y)
	{
		...
	}
	int x = 5;
	doSomethingCool(x);
```
4) What are two reasons you might want to turn off code optimization?
If you're debugging code optimized code could cause you to skip a line. If you're using a new compiler and it's not working it's good to turn off your optimizations to find out if the problem is with the compiler or the code.
5) When you run `gcc` with `-S`, why might the results look different on different computers?
Running `gcc` with `-S` outputs a file containing the assembly version of the compiled program. The opcodes that are used in the assembly are dependent on the instruction set provided by the architecture of the computer on which `gcc` is run. 
6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?
Mispelling a variable name results in a compile time error. However, mispelling a function name will compile but fail to link. 
7) What is a segmentation fault?
A segmentation fault is when you try to read or write to/from memory that the process does not have permission to use.

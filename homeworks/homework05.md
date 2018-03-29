## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/TShapinsky/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

If you applied sign extension 128 has a 1 in the leftmost bit (in 8-bit representation) so it would be interpreted as some negative number.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

```C
int x = 12;
int o = (((long)1<<32)-1) ^ x - 1;
```

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

To make comparison of floating point numbers easier, you just have to compare magnitudes of exponents instead of needing to convert from two's complement. Using a sign bit would be fairly easy for comparison but you'd still need a special case for the MSB.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

11000001010100000000000000000000

-1051721728

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```C
void toUpper(char * s){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
	printf("%c\n",*(s+i));
	*(s+i) &= ~(1<<5);
    }
}
```




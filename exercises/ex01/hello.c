#include <stdio.h>

int main() {
  //when the x variable is not used in the program it is omitted by the optimized version of the assembly
  int x = 5;
  //without optimization both x and y are stored as local variables
  int y = x + 1;
  
  //when x is added to printf the `call` in the assembly changed from calling `puts` and `printf`
  //x is also instead of being stored as a local variable (relative to `%rbp`), the value 5 is moved directly to the parameter of printf (register `%edx`)
  //when y is printed and the code is optimized the value 6 is moved directly to printf's parameter (register `%edx`)
  printf("Hello, World! %d\n",y);
    return 0;
}

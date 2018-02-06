#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adder.h"

#define SIZE 5

int main(void){
  int index = 0;
  int * val = malloc(sizeof(int));
  int sum = 0;
  while(!get_int(val)){
    sum += *val;
  }
  printf("sum: %d\n",sum);
  return 0;
}

/**
 * This method attempts to read an integer from the user
 * @param val pointer to where the value read should be stored
 * @return error code (0 is ok)
 */
int get_int(int * val){
  int * in = malloc(sizeof(int));
  int len = scanf("%d",in);
  if(len > 0){
    *val = *in;
    free(in);
    return 0;
  }
  free(in);
  return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "adder.h"

#define SIZE 5

/**
 * This function initializes variables and runs the main loop
 */
int main(void){
  int index = 0;
  int * buff = malloc(sizeof(int)*SIZE);
  int sum = 0;
  int val = 0;
  int err = 0;
  while(1){
    err = get_int(&val);
    if(!err){
      *(buff+index++) = val;
    }else if(err == 1){
      break;
    }
    if(index >= SIZE){
      printf("Exceeded array size\n");
      break;
    }
  }
  for(int i = 0; i < index; i++){
    sum += *(buff+i);
  }
  printf("sum: %d\n",sum);
  return 0;
}

/**
 * This function attempts to read an integer from the user
 * @param val This is a pointer to where the integer should be stored once querried
 * @return this is an error code (0 means no error)
 */
int get_int(int * val){
  char * in = malloc(sizeof(int)*12);
  int len = scanf("%s", in);
  if(len > 12){
    printf("Input exceeds buffer size\n");
    return 2;
  }
  if(len > 0){
    *val = atoi(in);
    if(*val > 0 || isdigit(*in)){
      free(in);
      return 0;
    }else{
      printf("Input must be an integer\n");
    }
  }
  free(in);
  return 1;
}

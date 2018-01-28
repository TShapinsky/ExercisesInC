#include <stdio.h>
#include <stdlib.h>
#include "cards_improved.h"

int main () {
  int count = 0;
  int val;
  char * card_name = malloc(sizeof(char)*3);
  do {
    get_card_name(card_name);
    val = get_card_value(card_name);
    if(val > 0){
      adjust_count(val, &count);
      printf("Current count: %i\n",count);
    }else if (val == -1){
      puts("I don't understand that value!");
    }else if (!val){
      break;
    }
  }while(TRUE);
  free(card_name);
  return 0;
}

void adjust_count(int val, int * count){
  if ((val > 2) && (val < 7)) {
    (*count)++;
    } else if (val == 10) {
    (*count)--;
    }
}

int get_card_value(char * card_name){
  int val = 0;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      break;
    default:
      val = atoi(card_name);
      if((val < 1) || (val > 10)){
	return -1;
      }
    }
  return val;
}

void get_card_name(char * card_name){
  puts("Enter the card name: ");
  scanf("%2s", card_name);
}

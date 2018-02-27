#include <string.h>
#include <assert.h>
#include "util.h"
#include "../minunit.h" 


static char *test1() {
    struct timeval out;
    struct timeval in;
    time(&(out.tv_sec));
    in.tv_sec = out.tv_sec;
    out.tv_usec = 500;
    in.tv_usec = 400;
    tv_sub(&out, &in);
    char *message = "test1 failed: tv_usec should be 100";
    mu_assert(message, out.tv_usec == 100);
    return NULL;
}

int main(void){
    char *result = test1();
    if(result != NULL) {
	printf("%s\n", result);
    }else{
	printf("ALL TESTS PASSED\n");
    }
}

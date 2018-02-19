#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#define TRUE 1;
#define FALSE 0;
typedef int bool;
//one different thing in the professional code is that they use a linked list to store their file pointers, I thought about doing this but decided against it. It is cleaner but less space efficient
bool APPEND = FALSE;
bool IGNORE_INTERRUPTS = FALSE;
FILE * * files = NULL;
int numFiles = 0;

bool beginsWith(char *s, char *prefix){
    int prefLen = strlen(prefix);
    for(int i = 0; i < prefLen; i++){
	if(*(s+i) != *(prefix+i)){
	    return FALSE;
	}
    }
    return TRUE;
}

void writeToFiles(char * s){
    for(int i = 0; i < numFiles; i++){
	fprintf(*(files+i),"%s\n",s);
	fflush(*(files+i)); //not having this flush caused a bit of a slowdown because no output was showing up, this caused me to try to debug pointers and a few other things which were actually working
    }
}

void doReadWriteLoop(){
    char * input = malloc(30); //if I had more time I'd fix this hack so that the intput can be of arbitrary length
    while(1){
	scanf("%s",input);
	printf("%s\n",input);
	writeToFiles(input);
    } 
}

void sigintHandler(int sig_num)
{
    if(IGNORE_INTERRUPRS){
	signal(SIGINT, sigintHandler);
    }else{
	for(int i = 0; i < numFiles; i++){
	    fclose(*(files+i));
	}
    }
}

int main(int argc, char *argv[]){
    int firstFileIndex = 0;
    //If I had read the documentation better I could have done this nicer. my initial idea was just to treat everything without a prefix "-" as a file but then I checked the docs and the options are explicitly before the files
    for(int i = 1; i < argc; i++){
	char * arg = argv[i];
	if(beginsWith(arg, "-")){
	    if(!(strcmp(arg,"-a") && strcmp(arg,"--append"))){
		APPEND = TRUE;
	    }else if(!(strcmp(arg,"-i") && strcmp(arg,"--ignore-interrupts"))){
		signal(SIGINT, sigintHandler);
		IGNORE_INTERRUPTS = TRUE;
	    }else{
		printf("invalid argument\n");
		return -1;
	    }
	}else{
	    if(!firstFileIndex){
		firstFileIndex = i;
		files = malloc(sizeof(FILE *)*(argc-firstFileIndex));
		numFiles = argc-firstFileIndex;
	    }
	    char* mode = "w";
	    if(APPEND){
		mode = "a";
	    }
	    FILE * file = fopen(arg,mode);
	    *(files+i-firstFileIndex) = file;
	}
    }
    doReadWriteLoop();
    return 0;
}

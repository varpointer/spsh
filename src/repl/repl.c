#include"repl.h"
#include<stdio.h>
#include"../constants.h"

extern void process_input(char input[INPUT_SIZE], FILE *outstream, FILE *errstream);

void run_repl(){
        printf("SpSH shell // Simplified shell\n");
	char input[INPUT_SIZE];
        while (1){
                printf("[spsh] ");
		fgets(input, INPUT_SIZE, stdin);
		process_input(input, stdout, stderr);
        }
}


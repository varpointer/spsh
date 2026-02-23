#include"repl.h"
#include<stdio.h>
#include"../constants.h"
#include<limits.h>
#include<stdlib.h>

extern void process_input(char *input, FILE *outstream, FILE *errstream);

void run_repl(){
        printf("SpSH shell // Simplified shell\n");
	char *input;
        for (;;){
                printf("[spsh] ");
		input = read_line();
		if ((long)input == -1){
			printf("Input too long; longer than %d", UINT_MAX);
			continue;
		}
		process_input(input, stdout, stderr);
		free(input);
        }
}

char* read_line(){
	char *input = (char *) malloc(sizeof(char));
	unsigned int input_index = 0;
	char c;
	for (;;input_index++){
		if (input_index == UINT_MAX){
			return (char *)(long)-1; // String too long
		}
		if (input_index % INPUT_BUFFER_FACTOR == (INPUT_BUFFER_FACTOR-1)){
			printf("NOT IMPLEMENTED -- TOO LONG\n");
		}
		char c = fgetc(stdin);
		if (c == '\n') {
			input[input_index] = '\0';
			return input;
		}
		input[input_index] = c;
	}
}


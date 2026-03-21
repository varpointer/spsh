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
	char *input = (char *) malloc(INPUT_BUFFER_FACTOR);
	unsigned int input_index = 0;
	char c;
	unsigned int buffer_size = 1;
	for (;;input_index++){
		if (input_index == UINT_MAX){
			return (char *)(long)-1; // String too long
		}
		if (input_index % INPUT_BUFFER_FACTOR == (INPUT_BUFFER_FACTOR-1)){
			buffer_size++;
			input = (char *)realloc(input, INPUT_BUFFER_FACTOR*buffer_size);
		}
		char c = fgetc(stdin);
		if (c == '\n') {
			input[input_index] = '\0';
			printf("%d\n", input_index);
			return input;
		}
		input[input_index] = c;
	}
}


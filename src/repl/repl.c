#include"repl.h"
#include<stdio.h>
#include"../constants.h"
#include<limits.h>
#include<stdlib.h>
#include "../shell/token_list.h"
#include "../shell/input.h"

void run_repl(){
        printf("SpSH shell // Simplified shell - Version %d.%d.%d\n", VER_MAJOR, VER_MINOR, VER_PATCH);
	char *input;
	TokenList tokens = new_token_list();
        for (;;){
		if (!tokens.is_incomplete){
			empty_token_list(tokens);
			tokens = new_token_list();
			printf("[spsh] ");
		} else
			printf("> ");
		input = read_line();
		if ((long)input == -1){
			printf("Input too long; longer than %d", UINT_MAX);
			continue;
		}
		process_input(input, stdout, stderr, &tokens);
		free(input);
        }
}

char* read_line(){
	char *input = (char *) malloc(INPUT_BUFFER_FACTOR);
	unsigned int input_index = 0;
	char c;
	unsigned int buffer_size = INPUT_BUFFER_FACTOR;
	for (;;input_index++){
		if (input_index == UINT_MAX){
			return (char *)(long)-1; // String too long
		}
		if (input_index >= buffer_size){
			buffer_size += INPUT_BUFFER_FACTOR;
			input = (char *)realloc(input, buffer_size);
		}
		char c = fgetc(stdin);
		if (c == '\n') {
			input[input_index] = '\0';
			return input;
		}
		input[input_index] = c;
	}
}


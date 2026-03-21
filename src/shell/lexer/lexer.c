#include "lexer.h"
#include<stdlib.h>
#include "../../constants.h"
#include<stdio.h>
char * get_next_token(char **input, char delimiter){
	char c;
	char *token = (char *) malloc( TOKEN_BUFFER_FACTOR );
	int index = 0;
	c = **input;
	int token_size = 1;

	for (;;){
		c = **input;

		if (index == (token_size * TOKEN_BUFFER_FACTOR)){
			token_size++;
			token = realloc(token, token_size * TOKEN_BUFFER_FACTOR);
			if (token == 0){
				printf("Memory allocation error\n");
				abort();
			}
		}

		if ((c == delimiter) || (c == 0)) {
			token[index] = '\0';
			return token;
		}
		token[index] = c;
		*input += 1;
		index++;
	}
}

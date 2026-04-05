#include "lexer.h"
#include<stdlib.h>
#include "../../constants.h"
#include<stdio.h>
char * get_next_token(char **input, char delimiter){
	char c;
	char *token = (char *) malloc( TOKEN_BUFFER_FACTOR );
	int index = 0;
	c = **input;
	int token_size = TOKEN_BUFFER_FACTOR;

	for (;;){
		c = **input;

		if (index == (token_size)){
			token_size += TOKEN_BUFFER_FACTOR;
			token = realloc(token, token_size);
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

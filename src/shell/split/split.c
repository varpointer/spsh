#include "split.h"
#include<stdlib.h>
#include "../../constants.h"
#include<stdio.h>
char * get_next_token(char **input, char delimiter){
	char c;
	char *token = (char *) malloc( sizeof(char *) * MAX_TOKEN_SIZE);
	int index = 0;
	c = **input;

	for (;;){
		if (index + 1 >= MAX_TOKEN_SIZE){
			exit(-1);
		}
		c = **input;
		if ((c == delimiter) || (c == 0)) {
			token[index] = '\0';
			return token;
		}
		token[index] = c;
		*input += 1;
		index++;
	}
}

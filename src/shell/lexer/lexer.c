#include "lexer.h"
#include<stdlib.h>
#include "../../constants.h"
#include<stdio.h>
int get_next_token(char **input, char delimiter, char **token, int *index){
	/*
	 * If 0 is returned, then it is a complete token with clsoed quotes.
	 * If 1 is returned, there were unclosed quotes, and the caller should require more.
	 */

	char c;

	c = **input;
	int token_size;
	int in_quotes;
	int has_quotes;

	if (*index == 0){
		token_size = TOKEN_BUFFER_FACTOR;
		in_quotes = 0;
		has_quotes = 0;
	}
	else {
		token_size = ((*index) / TOKEN_BUFFER_FACTOR) * TOKEN_BUFFER_FACTOR;
		in_quotes = 1;
		has_quotes = 1;
	}

	for (;;){
		c = **input;

		if (*index >= (token_size)){
			token_size += TOKEN_BUFFER_FACTOR;
			*token = realloc(*token, token_size);
			if (token == 0){
				printf("Memory allocation error\n");
				abort();
			}
		}

		if (c == '"'){
			in_quotes = !in_quotes;
			has_quotes = 1;
		}
		else if ((c == delimiter) && (*index == 0) && !has_quotes);
		else if (((c ==delimiter) && !in_quotes)) {
			(*token)[*index] = '\0';
			return 0;
		}
		else if (c == 0){
			if (!in_quotes){
				(*token)[*index] = '\0';
				return 0;
			}
			(*token)[*index] = '\n';
			return 1;
		}
		else {
			(*token)[*index] = c;
			(*index)++;
		}
		*input += 1;
		
	}
		
}

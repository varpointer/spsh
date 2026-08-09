#include "input.h"
#include<stdlib.h>
#include "lexer/lexer.h"

void process_input(char *input, FILE *outstream, FILE *errstream, TokenList *tokens){
	char *next;
	char *token;
	int result;
	int token_index;

	for (;;){
		if (!tokens->is_incomplete){
			token_index = 0;
			token = malloc(sizeof(char) * TOKEN_BUFFER_FACTOR);
		} else{
			token = tokens->tokens[tokens->token_count-1];
			token_index = tokens->last_token_len;
		}
		result = get_next_token(&input, ' ', &token, &token_index);

		if (tokens->last_token_len == 0)
			append_token(tokens, token);

		if (result == 1) {
			tokens->is_incomplete = 1;
			tokens->last_token_len = token_index+1;
			return;
		} else{
			tokens->is_incomplete = 0;
			tokens->last_token_len = 0;
			fputs(token, outstream);
			fputc('\n', outstream);
			if (*input == 0) break;
		}
		input += 1;
	}

}


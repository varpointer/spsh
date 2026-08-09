#include "./token_list.h"
#include<stdio.h>
#include<stdlib.h>
#include "../constants.h"

void append_token(TokenList *tokens, char *token){
	if (tokens->token_count == tokens->size){
		tokens->size += TOKEN_LIST_FACTOR;
		tokens->tokens = realloc(tokens->tokens, tokens->size * sizeof(char*));
	}
	tokens->tokens[tokens->token_count] = token;
	tokens->token_count++;
}

TokenList new_token_list(){
	TokenList tokens = {
		malloc(TOKEN_LIST_FACTOR * sizeof(char*)),
		0,
		TOKEN_LIST_FACTOR,
		0,
	};
	return tokens;
}

void empty_token_list(TokenList tokens){
	for (int i=0; i<tokens.token_count; i++){
		free(tokens.tokens[i]);
	}
	free(tokens.tokens);
	tokens.size = 0;
	tokens.is_incomplete = 0;
	tokens.last_token_len = 0;
}


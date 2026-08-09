#ifndef SPSH_TOKENLIST
#define SPSH_TOKENLIST

typedef struct {
	char **tokens;
	int token_count;
	int size;
	int is_incomplete; // 1 if the last token requires more input
	int last_token_len;
	
} TokenList;

TokenList new_token_list();

void append_token(TokenList *tokens, char *token);

void empty_token_list(TokenList tokens);

#endif

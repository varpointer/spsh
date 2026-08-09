#ifndef SPSH_INPUT
#define SPSH_INPUT

#include "../constants.h"
#include <stdio.h>
#include "./token_list.h"

void process_input(char *input, FILE *outstream, FILE *errstream, TokenList *tokens);

#endif

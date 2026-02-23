#include "input.h"
#include<stdlib.h>

extern char * get_next_token(char **input, char delimiter);

void process_input(char *input, FILE *outstream, FILE *errstream){
	fprintf(outstream, "PROCESSED: %s\n", input);
	char *next;
	
	for (;;){
		next = get_next_token(&input, ' ');
		fputs(next, outstream);
		free(next);
		fputc('\n', outstream);
		if (*input == 0) break;
		input += 1;
	}
}


#include "input.h"

void process_input(char input[INPUT_SIZE], FILE *outstream, FILE *errstream){
	fprintf(outstream, "PROCESSED: %s", input);
}


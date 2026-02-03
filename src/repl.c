#include"repl.h"
#include<stdio.h>

void run_repl(){
        printf("SpSH shell // Simplified shell\n");
	char input[1000];
        while (1){
                printf("[spsh] ");
		fgets(input, 1000, stdin);
		printf("%s", input);
        }
}


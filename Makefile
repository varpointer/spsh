main_files = src/main.c src/repl/repl.c src/shell/input.c src/shell/lexer/lexer.c src/shell/token_list.c

spsh: $(main_files)
	cc $(main_files) -o bin/spsh

debug: $(main_files)
	cc $(main_files) -o bin/spsh_debug -g

#test: $(main_files)

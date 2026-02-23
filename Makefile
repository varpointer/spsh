main_files = src/main.c src/repl/repl.c src/shell/input.c src/shell/split/split.c

spsh: $(main_files)
	cc $(main_files) -o bin/spsh

test: $(main_files)
	echo "No implemented tests, compiling as normal."
	cc $(main_files) -o bin/spsh_test


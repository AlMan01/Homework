#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TOK_BUFFER_SIZE 100
#define TOK_DELIM "\t\n"

void inf_loop() {
	char* line;
	char** args;
	int status;
	do {
		printf(">");
		line = read_line();
		args = split_line(line);
		status = execute(args);
		free(line);
		free(args);
	}while(status);
}

char* read_line() {
	int BUFFER_SIZE, i = 0;
	char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
	int c;
	if(!buffer)
		printf("THE MEMORY IS NOT ALOCCATED\n");
		exit();
	while(1) {
		c = get_char();
		if(c == EOF || c == '\n') {
			buffer[i] = '\0';
			return buffer;
		}
		else {
			buffer[i] = c;
		}
		++i;
		if(i >= BUFFER_SIZE){
			BUFFER_SIZE += BUFFER_SIZE;
			buffer = malloc(sizeof(char) * BUFFER_SIZE);
			if(!buffer) {
				printf("THE MEMORY IS NOT ALOCCATED\n");
				exit();
			}
		}
	}

}

void split_line(char* line) {
	int buffer = TOK_BUFFER_SIZE, position = 0;
	char** tokens = malloc(buffer * sizeof(char*));
	char* token;
	if(!tokens) {
		printf("THE MEMORY IS NOT ALOCCATED\n");
		exit();
	}
	token strtok(line, TOK_DELIM);
	while(token != NULL) {
		tokens[position] = token;
		position++;
		if(position >= buffer) {
			buffer += TOK_BUFFER_SIZE;
			tokens = malloc(buffer * sizeof(char*));
			if(!tokens) {
				printf("THE MEMORY IS NOT ALOCCATED\n");
			}
			exit();
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

int main(int argc, char* argv[]) {
	inf_loop();
}

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TOK_BUFFER_SIZE 100
#define TOK_DELIM "\t\n"

struct datas {
	char* line;
	char** args;
	int status;
};

void inf_loop(const datas& d) {
	do {
		printf(">");
		d->line = read_line();
		d->args = split_line(line);
		d.status = execute(const datas& d);
		free(line);
		free(args);
	}while(status);
}

char* read_line() {
	int i = 0;
	char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
	int c;
	if(!buffer) {
		printf("THE MEMORY IS NOT ALOCCATED\n");
		exit(EXIT_FAILURE);
	}
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
			int BUFFER_SIZE_2 = 2 * BUFFER_SIZE;
			free(buffer);
			buffer = malloc(sizeof(char) * BUFFER_SIZE_2);
			if(!buffer) {
				printf("THE MEMORY IS NOT ALOCCATED\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(buffer);

}

void split_line(char* line) {
	assert(line);
	int tok_size = TOK_BUFFER_SIZE, position = 0;
	char** tokens = malloc(tok_size * sizeof(char*));
	char* token;
	if(!tokens) {
		printf("THE MEMORY IS NOT ALOCCATED\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while(token != NULL) {
		tokens[position] = token;
		position++;
		if(position >= tok_size) {
			int tok_size_2 = 2 * TOK_BUFFER_SIZE;
			free(tok_size);
			tokens = malloc(tok_size_2 * sizeof(char*));
			if(!tokens) {
				printf("THE MEMORY IS NOT ALOCCATED\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	free(tok_size_2);
	return tokens;
}

int execute(const datas& d) {
	int rc = fork();
	if(rc < 0) {
		fprintf(strerr, "FORK FAILED\n");
		exit(1);
	}
	else if(rc == 0) {
		close(STDOUT_FILENO);
		open("./Alex_&_Arno's_sh_output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		execvp(d->args[0], d->args);
	}
	else {
		int rc_wait = wait(NULL);
	}
	return 0;
}

int main(int argc, char* argv[]) {
	inf_loop(data);
	return 0;
}

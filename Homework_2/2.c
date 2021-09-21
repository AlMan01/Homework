#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void list_file_recurs(char *basepath);

int main(int argc, char *argv[])
{
	listfr(argv[1]);
	return 0;
}
void list_file_recurs(char *basepath)
{
	struct dirent *d;
	char path[10];
	DIR *dir = opendir(basepath);
	if(!dir)
	{
		return;
	}
	while((d = readdir(dir)) != NULL)
	{
		if(strcmp(d-> d_name, ".") != 0 && strcmp(d-> d_name, "..") != 0)
		{
			printf("%s\n", d->d_name);
			strcpy(path, basePath);
			strcat(path, "/");
			strcat(path, d->d_name);
			list_file_recurs(path);
		}
	}
	closedir(dir);
}

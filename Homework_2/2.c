#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listfr(char *basePath);

int main()
{
	char path[100];
	printf("Enter path to list files: ");
	scanf("%s", path);
	listfr(path);
	return 0;
}
void listfr(char *basePath)
{
	struct dirent *dp;
	char path[1000];
	DIR *dir = opendir(basePath);
	if(!dir)
		return;
	while((dp = readdir(dir)) != NULL)
	{
		if(strcmp(dp-> d_name, ".") != 0 && strcmp(dp-> d_name, "..") != 0)
		{
			printf("%s\n", dp->d_name);
			strcpy(path, basePath);
			strcat(path, "/");
			strcat(path, dp->d_name);
			listfr(path);
		}
	}
	closedir(dir);
}

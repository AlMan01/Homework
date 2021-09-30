#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void lfr(char *basepath);

int main(int argc, char *argv[])
{
	lfr(argv[1]);
	return 0;
}

void lfr(char *basepath)
{
	//DIR - directory stream, which is an ordered sequence of all the directory entries in a particular directory;
	//readdir() returns a pointer to a structure representing the directory entry at the current position in the directory stream specified by the argumenq dirp, and positions the direct	      //ory stream at the next entry;
	struct dirent *d; //will return info about directory etries
	char path[100];
	DIR *dir = opendir(basepath); // will return a pointer to an object of typy DIR; (dir)
	if(!dir)
	{
		return;
	}
	while((d = readdir(dir)) != NULL)
	{
		if(strcmp(d-> d_name, ".") != 0 && strcmp(d-> d_name, "..") != 0) //d_name - represent the directory entry's filename; strcmp - if d-> d_name == "." return 0
		{
			printf("%s\n", d-> d_name);
			strcpy(path, basepath);
			strcat(path, "/");
			strcat(path, d-> d_name);
			lfr(path);
		}
	}
	closedir(dir);
}

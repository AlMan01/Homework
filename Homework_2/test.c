#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	FILE *files[n];
	for(int i = 1; i <= n; ++i)
	{
		char name[20];
		sprintf(name, "Results%d.txt", i);
		files[i] = fopen(name, "w");
		fprintf(*(files + i), "Hallo, World<i-th>\n");
	}
	return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 5
int result = 0;

void* reduce(void *(f_p)(void*), void *d_p) {
	pthread_t threads[N];
	for(int i = 0; i < N; ++i) {
		pthread_t p;
		pthread_create(&p, NULL, f_p, d_p + (i * 5));
		threads[i] = p;
	}
	for(int i = 0; i < N; ++i) {
		pthread_join(threads[i], NULL);
	}

	return (void*)&result;
}

void* f_p(void *arr) {
	int* intArr = (int*)arr;
	for(int i = 0; i < N; ++i) {
		result += intArr[i];
	}
	return (void*)&result;
}

int main(int argc, char** argv) {
	const int size = 15;
	int arr[] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int *res = (int*)reduce(f_p, arr);
	printf("%d", *res);
	return 0;
}



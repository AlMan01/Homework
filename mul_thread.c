#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 5
int arr[] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void* reduce(void (f_p)(void), void *d_p) {
	pthread_t th[N];
    int i;
    for (i = 0; i < N; i++) {
        int* a = malloc(sizeof(int));
        *a = i * N;
        if (pthread_create(&th[i], NULL, &f_p, a) != 0) {
            perror("Failed to create thread");
        }
    }
    int globalSum = 0;
    for (i = 0; i < N; i++) {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed to join thread");
        }
        globalSum += *r;
        free(r);
    }
  printf("%d",globalSum);
	return (void*)&globalSum;
}

void* f_p(void *arg) {
	int index = (int)arg;
    int sum = 0;
    for (int j = 0; j < 5; j++) {
        sum += arr[index + j];
    }
    printf("Local sum: %d\n", sum);
    (int)arg = sum;
    return arg;
}

int main(int argc, char** argv) {
	reduce(f_p, arr);
	return 0;
}

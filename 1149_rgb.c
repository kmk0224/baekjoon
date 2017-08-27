#include <stdio.h>
#include <stdlib.h>

// fail

int *ptr = NULL;

int main(){
	int n = 0;
	int total = 0;
	int prex = -1;

	// initialize input
	scanf("%d", &n);
	if(n > 1000){
		printf("incorrect input\n");
		return 0;
	}

	ptr = (int *)malloc(sizeof(int) * n *3);
	for(int i = 0; i< n * 3; i++){
		scanf("%d", &ptr[i]);
	}

	// algorithm
	for(int i = 0; i < n * 3; i = i + 3){
		int min = i;
		for(int j = i; j < i + 2; j++){
			if(prex != j%3){
				if(ptr[min] > ptr[j + 1]){
					min = j + 1;
					prex = (j + 1) % 3;
				}
			}
		}
		total = total + ptr[min];
	}
	printf("%d\n", total);
	free(ptr);
	return 0;
}

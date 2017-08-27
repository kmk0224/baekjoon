#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, max, min;
	int *arr;
	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);
	for(int i = 0; i<n ;i++){
		scanf("%d", arr + i);
	}

	max = arr[0];
	min = arr[0];

	for(int i = 1; i<n; i++){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}

	printf("%d %d\n", min, max);
	return 0;
}

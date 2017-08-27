#include <stdio.h>


int main(void){
	int n, count = 0;
	int arr[10] = {0,};

	scanf("%d", &n);
	
	while(1){
		if(n >= 10){
			arr[n % 10]++; 
			n = n / 10;
		}else{
			arr[n]++;
			break;
		}
	}

	arr[6] += arr[9];
	arr[9] = 0;
	if(arr[6] % 2 == 1)
		arr[6]++;
	arr[6] = arr[6] /2;


	int max = 0;
	for(int i = 1; i < 10; i++){
		if(arr[max] < arr[i])
			max = i;
	}
	printf("%d\n", arr[max]);

	return 0;
}

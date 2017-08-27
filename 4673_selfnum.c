#include <stdio.h>

int main(){
	int a, b, c, d, e, result;
	int arr[10000] = {0, };


	for(int num = 1; num <= 10000; num++){
		// find self number
		a = num / 10000;
		b = (num % 10000) / 1000;
		c = (num % 1000) / 100;
		d = (num % 100) / 10;
		e = (num % 10);

		//printf("%d %d %d %d %d\n", a, b, c, d, e);
		result = num + a + b + c + d + e;

		if(result <= 10000){
			arr[result] = 1;
		}
	}


	for(int i = 1; i <= 10000; i++){
		if(arr[i] == 0){
			printf("%d\n", i);
		}
	}
	return 0;
}

#include <stdio.h>

int main(void){
	int x, i;
	int result[2] = {0,};

	scanf("%d", &x);
	if(x < 1 || x > 10000000)
		return 0;

	i = 1;
	while(1){
		if(i < x){
			x -= i;
			i++;
		}
		else{
			x--;
			break;
		}
	}
	//printf("%d %d\n", i, x);
	if(i % 2 == 1){
		result[0] = i;
		result[1] = 1;
		for(int j = 0; j < x; j++){
			result[0]--;
			result[1]++;
		}
	}
	else{
		result [0] = 1;
		result [1] = i;
		for(int j = 0; j<x; j++){
			result[0]++;
			result[1]--;
		}
	}
	printf("%d/%d\n",result[0], result[1]);
	return 0;
}

#include <stdio.h>

int main(void){
	int n, i = 0;
	
	scanf("%d", &n);
	if(n < 1 || n > 1000000000)
		return 0;


	while(1){
		if(i == 0){
			if(n <= 1){
				break;
			}else{
				n -= 1;
				i++;
			}
		}else{
			if( n <= 6 * i){
				break;
			}else{
				n -= 6 * i;
				i++;
			}
		}
	}

	printf("%d\n", i + 1);
	return 0;
}

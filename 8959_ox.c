#include <stdio.h>
#include <string.h>
#define max 81

int main(){
	char arr[max];
	int num, sum = 0;
	scanf("%d", &num);

	for(int _num = 0; _num < num; _num++){
		// initialize arr
		for(int i = 0; i < max; i++){
			arr[i] = '\0';
		}
		sum = 0;
		//gets(arr);
		scanf("%s", arr);
		
		int sub = 0;
		for(int i = 0; arr[i] != '\0'; i++){
			if(arr[i] == 'X'){
				sub = 0;
			}else{
				sub++;
				sum += sub;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}

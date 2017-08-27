#include <stdio.h>
#define max 1000001

int main(){
	char arr[max];
	int count = 0;
	int i = 0;
	
	for(int i = 0; i < max; i++){
		arr[i] = '\0';
	}
	gets(arr);

	while(1){
		if(arr[i] == '\0'){
			if(i !=0 && arr[i-1] != ' ')
				count++;
			break;
		}else if(arr[i] == ' '){
			if(i != 0 && arr[i-1] != ' ')
				count++;
		}
		i++;
	}
	printf("%d\n", count);

	return 0;
}

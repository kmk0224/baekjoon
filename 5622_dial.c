#include <stdio.h>
#include <string.h>


int main(){
	char input[16];
	int result = 0;
	
	for(int i = 0; i<16; i++){
		input[i] = '\0';
	}

	scanf("%s", input);

	if(!(strlen(input) <=15 && strlen(input)>=2))
		return 0;

	for(int i = 0; i < strlen(input); i++){
		if(input[i] >= 'A' && input[i] <= 'C'){
			result += 2;
		}
		else if(input[i] >= 'D' && input[i] <= 'F'){
			result += 3;
		}
		else if(input[i] >= 'G' && input[i] <= 'I'){
			result += 4;
		}
		else if(input[i] >= 'J' && input[i] <= 'L'){
			result +=5;
		}
		else if(input[i] >= 'M' && input[i] <= 'O'){
			result += 6;
		}
		else if(input[i] >= 'P' && input[i] <= 'S'){
			result += 7;
		}
		else if(input[i] >= 'T' && input[i] <= 'V'){
			result += 8;
		}
		else if(input[i] >= 'W' && input[i] <= 'Z'){
			result += 9;
		}
		else{
			result += 10;
		}
		result++;
	}
	printf("%d\n", result);
	return 0;
}

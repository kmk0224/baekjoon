#include <stdio.h>
#include <string.h>

#define max 101

int main(void){
	char *croatia[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}; 
	char input[101];
	int total = 0,  i = 0, j = 0;

	for(int i = 0; i < max; i++){
		input[i] = '\0';
	}
	
	scanf("%s", input);
	
	if(strlen(input) >100)
		return 0;
	
	while(i < strlen(input)){
		for(j = 0; j < 8; j++){
			if(strncmp(croatia[j], input + i, strlen(croatia[j])) == 0){
				i += strlen(croatia[j]);
				total++;
				break;
			}
		}

		if(j == 8){
			i++;
			total++;
		}
	}
	printf("%d\n", total);
	
	return 0;
}

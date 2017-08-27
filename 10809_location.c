#include <stdio.h>
#include <string.h>

int main(){
	char input[101] = {0,};
	int location[26];

	for(int i = 0; i< 26; i++){
		location[i] = -1;
	}
	scanf("%s", &input);

	for(int i = 0; i < strlen(input) ; i++){
		if(location[input[i] - 'a'] == -1){
			location[input[i] - 'a'] = i;
		}
	}

	for(int i = 0; i < 26; i++){
		printf("%d ", location[i]);
	}
	return 0;
}

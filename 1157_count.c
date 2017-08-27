#include <stdio.h>
#define max_length 1000001

int main(){
	char input[max_length];
	int alphabet[26];
	int select = 0;
	int duplicate = 0;
	int j = 0;

	// initialize
	for(int i = 0; i< max_length; i++){
		input[i] = '\0';
	}
	for(int i = 0; i<26; i++){
		alphabet[i] = 0;
	}
	scanf("%s", &input);
	while(input[j] != '\0'){
		if(input[j] >= 'a' && input[j] <= 'z'){ // small
			alphabet[input[j] - 'a']++;
		}
		else{	// big
			alphabet[input[j] - 'A']++;
		}
		j++;
	}

	select = 0;
	for(int i = 1; i<26; i++){
		if(alphabet[select] < alphabet[i]){
			select = i;
			duplicate = 0;
		}else if(alphabet[select] == alphabet[i]){
			duplicate++;
		}
	}

	if(duplicate > 0)
		printf("?\n");
	else{
		printf("%c\n", 'A' + select);
	}
	return 0;
}

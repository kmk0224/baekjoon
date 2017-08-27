#include <stdio.h>
#include <string.h>


int main(){
	int testcase_num = 0;
	int r = -1;
	char string[21];

	scanf("%d", &testcase_num);

	if(testcase_num <= 0 || testcase_num > 1000)
		return 0;

	for(int i = 0; i < testcase_num; i++){
		// initialize string
		for(int j = 0; j < 21; j++){
			string[j] = '\0';
		}

		scanf("%d", &r);
		if(r < 1 || r > 8)
			return 0;
		scanf("%s", &string);

		for(int j = 0; j < strlen(string); j++){
			for(int k = 0; k < r; k++){
				printf("%c", string[j]);
			}
		}
		printf("\n");
	}

	return 0;
}

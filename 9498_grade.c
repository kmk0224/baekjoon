#include <stdio.h>


int main(){
	int grade = 0;
	
	scanf("%d", &grade);
	
	if(grade < 0 || grade >101)
		return 0;

	if(grade >= 90)
		printf("A\n");
	else if(grade >= 80)
		printf("B\n");
	else if(grade >= 70)
		printf("C\n");
	else if(grade >= 60)
		printf("D\n");
	else
		printf("F\n");


	return 0;
}

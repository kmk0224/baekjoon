#include <stdio.h>

int digit[10000] = {0, };
int n;

int isPrev();

int main(){
	scanf("%d", &n);
	for(int x = 0; x < n; x++){
		scanf("%d", &digit[x]);
	}

	if(isPrev() == -1){
		printf("-1\n");
	}
	else{
		for(int x = 0; x < n; x++){
			printf("%d ", digit[x]);
		}
	}
	return 0;
}

int isPrev(){
	int i, j, tmp;

	i = n - 1;
	while(digit[i] >= digit[i - 1]){
		i--;
	}
	if(i <= 0)
		return -1;

	j = n - 1;
	while(digit[j] >= digit[i - 1]){
		j--;
	}

	// swap
	tmp = digit[i - 1];
	digit[i - 1] = digit[j];
	digit[j] = tmp;

	j = n - 1;
	while(i < j){
		tmp = digit[i];
		digit[i] = digit[j];
		digit[j] = tmp;
		i++;
		j--;
	}


	return 1;
}

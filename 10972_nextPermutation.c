// success

#include <stdio.h>

int main(){
	int n, i, j;
	int digit[10000] = {0, };

	// input
	scanf("%d", &n);

	for(int x = 0; x < n; x++){
		scanf("%d", &digit[x]);
	}

	// next permutation algorithm
	i = n - 1;
	while(digit[i] <= digit[i - 1] && i > 0){
		i--;
	}
	if(i <= 0){
		printf("-1\n");
		return 0;
	}

	j = n - 1;
	while(j >= i){
		if(digit[i - 1] <= digit[j])
			break;
		j--;
	}

	// swap
	int tmp = digit[j];
	digit[j] = digit[i - 1];
	digit[i - 1] = tmp;
/*
	for(int x = 0; x < (n - i)/2; x++){
		int x = digit[i + x];
		digit[i + x] = digit[n - 1 - x];
		digit[n - 1 - x] = x;
	}
  */
    j = n - 1;
    while(i < j){
        tmp = digit[i];
        digit[i] = digit[j];
        digit[j] = tmp;
        i++;
        j--;
    }

	for(int x = 0; x < n; x++){
		printf("%d ", digit[x]);
	}


	return 0;
}

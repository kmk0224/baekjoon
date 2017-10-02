#include <stdio.h>

int n;
int digit[8] = {0, };

int isNext();

int main(){
    
    // input
    scanf("%d", &n);

    for(int x = 0; x < n; x++){
		digit[x] = x + 1;
    }
	for(int x = 0; x < n; x++)
		printf("%d ", digit[x]);
	printf("\n");

	while(isNext()){
		for(int x = 0; x < n; x++)
			printf("%d ", digit[x]);
		printf("\n");
	}
	return 0;
}

int isNext(){
// next permutation algorithm
	int i, j;
    i = n - 1;
    while(digit[i] <= digit[i - 1] && i > 0){
        i--;
    }
    if(i <= 0){
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

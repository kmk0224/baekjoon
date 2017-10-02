#include <stdio.h>

int n, k, first;
int arr[20] = {0, };

int isNext();

int main(){
	scanf("%d", &n);
	scanf("%d", &k);

	if(k == 1){
		scanf("%d", &first);
	}else{

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

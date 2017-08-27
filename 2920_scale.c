#include <stdio.h>
#define size 8

int main(){
    int arr[size];
    int sub = 0;
    int flag = 0;
    
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    sub = arr[0] - arr[1];
    for(int i = 1; i < size -1; i++){
        int tmp = arr[i] - arr[i+1];
		//printf("%d\n", tmp);
        if(sub != tmp){
            flag = 1;
            break;
        }
    }
    
    if(flag == 1)
        printf("mixed\n");
    else if(sub > 0)
        printf("descending\n");
    else
        printf("ascending\n");
    
    return 0;
}

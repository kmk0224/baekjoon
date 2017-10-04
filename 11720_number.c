#include <stdio.h>

int main(){
    int n, x, result = 0;
    scanf("%d", &n);
    scanf("%d", &x);
    
    for(int i = 0; i < n ; i++){
        result += x % 10;
        x = x/10;
    }
    printf("%d\n", result);
    
    return 0;
}

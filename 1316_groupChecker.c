#include <stdio.h>
#include <string.h>

int main(void){
    int n = 0;
    char s[101];
    char alphabet[26] = {0, };
    int checker = 0;
    
    scanf("%d", &n);
    if(n <= 0 || n >= 100)
        return 0;
    
    for(int i = 0; i < n; i++){
        // initialize
        for(int j = 0; j < 101; j++){
            s[j] = '\0';
        }
        for(int j = 0; j < 26; j++){
            alphabet[j] = -1;
        }
        
        scanf("%s", s);
        
        int flag = 0; //replay
        for(int j = 0; j < strlen(s); j++){
            if(alphabet[s[j] - 'a'] == -1){
                alphabet[s[j] - 'a'] = j;
            }else{
                flag = 1;
                break;
            }
            while(s[j] == s[j+1]){
                j++;
            }
        }
        
        if(flag == 0)
            checker++;
    }
    
    printf("%d\n", checker);
    return 0;
}

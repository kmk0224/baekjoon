#include <stdio.h>

int main(){
	int n = 0;

	scanf("%d", &n);
	if(n > 100000)
		return 0;
	for(int i = 1; i<=n; i++){
		printf("%d\n", i);
	}
	return 0;
}

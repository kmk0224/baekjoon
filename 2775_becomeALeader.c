#include <stdio.h>
#include <stdlib.h>

int main(){
	int t, k, n; // t = testcase, k = kth floor, n = number of room
	int *base = NULL;

	scanf("%d", &t);

	for(int i = 0; i < t; i++){ // repeat the number of testcases
		scanf("%d %d", &k, &n);
		if(!(1 <= k && k <= 14) || !(1 <= n || n <= 14))
			return 0;

		//initialize
		base = (int *)malloc(sizeof(int) * (n) * 2);
		for(int i = 0; i < n; i++){
			base[i] = i + 1;
		}
//		// debug initialize
//		for(int i = 0; i < 2 * n ; i++){
//		printf("%d ", base[i]);
//		}
//
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < n ;j++){
				if(i % 2 == 0){
					if(j == 0)
						base[j] = base[j + n];
					else
						base[j] = base[j - 1] + base[j + n];
//					printf("%d ", base[j]);
				}else{
					if(j == 0)
						base[j + n] = base[j];
					else
						base[j + n] = base[j - 1 + n] + base[j];
//					printf("%d ", base[j + n]);
				}
			}
//			printf("\n");
		}

		if(k % 2 == 0){
			printf("%d\n", base[n - 1]);
		}else{
			printf("%d\n", base[n + n - 1]);
		}

		free(base);
	}
	
	return 0;
}

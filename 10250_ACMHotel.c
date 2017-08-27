#include <stdio.h>

int main(){
	int t, h, w, n, result = 0;

	scanf("%d", &t);

	for(int i = 0; i < t; i++){
		result = 0;
		scanf("%d %d %d", &h, &w, &n);
		if(h < 1 || w > 99 || n < 1 || n > h*w)
			return 0;

		int count = 0;
		for(int j = 1; j <= w; j++){
			for(int k = 1; k <= h; k++){
				count++;
				if(count == n){
					printf("%d%02d\n", k, j);
					break;
				}
			}
		}

	}
	return 0;
}

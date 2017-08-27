//fail

#include <stdio.h>

int main(void){
	// t = the number of test case
	int t = 0, m = 0, n = 0, x = 0, y = 0;

	scanf("%d", &t);

	for(int i = 0; i < t; i++){
		int count = 0, tmp_x = 1, tmp_y = 1;
		
		// input
		scanf("%d %d %d %d", &m, &n, &x, &y);

		while(1){
			if(tmp_x == x && tmp_y == y){
				count++;
				break;
			}
			else if(tmp_x == m && tmp_y == n){
				count = -1;
				break;
			}
			else{
				if(tmp_x < m)
					tmp_x++;
				else
					tmp_x = 1;
				if(tmp_y < n)
					tmp_y++;
				else
					tmp_y = 1;
//				printf("%d %d\n", tmp_x, tmp_y);
				count++;
			}
		}

		printf("%d\n", count);

	}

	return 0;
}

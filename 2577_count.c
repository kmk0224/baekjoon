#include <stdio.h>


int main(){
	int a, b, c, total;
	int score[10] = {0, };

	// get input
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if(a < 100 || a >= 1000)
		return 0;
	if(b < 100 || b >= 1000)
		return 0;
	if(c < 100 || c >= 1000)
		return 0;

	total = a * b * c;
	while(1){
		int sub = total % 10;
		total = total / 10;
		score[sub]++;
		if(total == 0)
			break;

	}

	for(int i = 0; i< 10; i++){
		printf("%d\n", score[i]);
	}

	return 0;
}

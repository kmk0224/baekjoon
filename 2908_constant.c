#include <stdio.h>
int transfer(int x);

int main(){
	int x, y;

	scanf("%d %d", &x, &y);

	x = transfer(x);
	y = transfer(y);

	if(x>y)
		printf("%d\n", x);
	else
		printf("%d\n", y);

	return 0;
}

int transfer(int x){
	int sub[3] = {0,};
	int new_x = x;
	int i = 0;

	while(1){
		if(new_x / 1 >= 10){
			sub[i] = new_x % 10;
			new_x = new_x / 10;
		}else{
			sub[i] = new_x;
			break;
		}
		i++;
	}
//	for(int i = 0 ; i<3; i++){
//		printf("%d", sub[i]);
//	}
//	printf("\n");
	return sub[0] * 100  + sub[1] * 10 + sub[2];
}

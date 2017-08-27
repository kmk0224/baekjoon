#include <stdio.h>
#include <string.h>
#define set_num 20

int main(){
	int m = 0;
	int s = 0;	//set
	char command[10];

	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		memset(command, '\0', sizeof(char) * 10);
		scanf("%s", command);

		if(!strcmp(command, "add")){
			int x = 0;
			scanf("%d", &x);
			x--;
			s = s | (1 << x);
		}
		else if(!strcmp(command, "remove")){
			int x = 0;
			scanf("%d", &x);
			x--;
			s = s & ~(1 << x);
		}else if(!strcmp(command, "check")){
			int x = 0;
			int res = 0;
			scanf("%d", &x);
			x--;
			res = s & (1 << x);
			if(res == 0)
				printf("0\n");
			else
				printf("1\n");
		}else if(!strcmp(command, "toggle")){
			int x = 0;
			scanf("%d", &x);
			x--;
			s = s ^ (1 << x);
		}
		else if(!strcmp(command, "all")){
			s = (1 << set_num) - 1;
		}else if(!strcmp(command, "empty")){
			s = 0;
		}
	}


	return 0;
}

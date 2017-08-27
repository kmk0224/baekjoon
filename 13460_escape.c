//www.acmicpc.net/problem/13460

// all pass, but 틀렸습니다

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG 1
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

typedef struct _pos{
	int x;
	int y;
}POS;

int n, m;
char ** maze = NULL;
POS red;
POS blue;
POS hole;
int dir = -1; // direction of red

void move_blue(int *flag_b);
void move_red(int * flag_r);
void solve(void);
int direction(int i, int j);

int main(void){
	// input
	scanf("%d %d\n", &n, &m);
	
	if(n <= 2 || n >= 11){	//check the scope
		return -1;
	}
	if(m <= 2 || m >= 11){
		return -1;
	}

	maze = (char**)malloc(sizeof(char*) * n);
	for(int i = 0; i < n; i++){
		char * _maze = (char*)malloc(sizeof(char) * m);
		maze[i] = _maze;

		for(int j = 0; j < m; j++){
			scanf("%c", &maze[i][j]);
			if(maze[i][j] == 'O'){
				hole.x = i;
				hole.y = j;
			}else if(maze[i][j] == 'R'){
				red.x = i;
				red.y = j;
				maze[i][j] = '.';
			}else if(maze[i][j] == 'B'){
				blue.x = i;
				blue.y = j;
				maze[i][j] = '.';
			}
		}
		getchar();	// remove '\n'
	}
	
//#ifdef DEBUG
//	for(int i = 0; i < n ; i++){
//		for(int j = 0; j < m ; j++){
//			printf("%c", maze[i][j]);
//		}
//		printf("\n");
//	}
//#endif

	solve();

	// free memory
	for(int i = 0; i< n; i++){
		free(maze[i]);
	}
	free(maze);

	return 0;
}

void solve(void){
	int cnt = 0;
	int result = -1;
	int flag_r = 0, flag_b = 0;

	while(flag_r == 0 && flag_b == 0 && cnt <=10){
		move_red(&flag_r);
		move_blue(&flag_b);
		cnt++;
#ifdef DEBUG
		printf("dir : %d\n", dir);
		printf("red (x,y) : %d %d\n", red.x, red.y);
		printf("blue (x,y) : %d %d\n", blue.x, blue.y);
		printf("red flag : %d, blue flag : %d\n", flag_r, flag_b);
		printf("-- cnt : %d\n\n", cnt);
#endif
	}

	if(cnt > 10 || flag_b == 1){
		result = -1;
		printf("%d\n",result);
		return;
	}

	if(flag_r == 1){
		printf("%d\n", cnt);
		return;
	}

}

void move_blue(int *flag_b){
	if(dir % 2 == 0){ //LEFT, RIGHT
		for(int j = blue.y; 0 <= j && j < m;){
			if(maze[blue.x][j] == 'O'){
				*flag_b = 1;
				blue.y = j;
				break;
			}else if(maze[blue.x][j] == '#' || (red.x == blue.x && red.y == j)){
				//	blue.y = j + 1;
				if(dir == LEFT)
					blue.y = j + 1;
				else
					blue.y = j - 1;
				break;
			}

			if(dir == LEFT){
				j--;
			}
			else{
				j++;
			}
		}
	}else{	//UP,DOWN
		for(int i = blue.x; 0 <= i && i < n;){
			if(maze[i][blue.y] == 'O'){
				*flag_b = 1;
				blue.x = i;
				break;
			}else if(maze[i][blue.y] == '#' || (red.x == i && red.y == blue.y)){
				//blue.x = i + 1;
				if(dir == UP)
					blue.x = i + 1;
				else
					blue.x = i - 1;
				break;
			}

			if(dir == UP){
				i--;
			}
			else{
				i++;
			}
		}
	}

}

void move_red(int * flag_r){
	int priority = 0;
	int tmp_dir = dir;
	int back = 0;

	// choose direction
	for(int i = -1; i <= 1 && priority == 0; i++){
		for(int j = -1; j <= 1; j++){
			if(((i == 0 && j != 0) || (i != 0 && j == 0)) ){ //십자모양만
#ifdef DEBUG
				printf("%d %d : ", red.x + i, red.y +j);
				printf("%c\n", maze[red.x + i][red.y + j]);
#endif
				if(red.x + i == hole.x && red.y + j == hole.y){ // next to hole 'O'
					priority = 1;
					dir = direction(i, j);
					break;
				}else if(maze[red.x + i][red.y + j] == '.' ){ 
					if(((tmp_dir + 2) %4) != direction(i,j)){ // remove walked path
						dir = direction(i, j);
						break;
					}
					else{
						back++;
					}

				}
			}
		}
	}

	if(back >= 3){
#ifdef DEBUG
		printf("no way\n");
#endif
		dir = (tmp_dir + 2)  % 4;
	}

	if(dir % 2 == 0){ //LEFT, RIGHT
		for(int j = red.y; 0 <= j && j < m; ){
			if(maze[red.x][j] == 'O'){
				*flag_r = 1;
				red.y = j;
				break;
			}else if(maze[red.x][j] == '#' || (red.x == blue.x && j == blue.y)){
				//	red.y = j + 1;
				if(dir == LEFT)
					red.y = j + 1;
				else
					red.y = j - 1;
				break;
			}

			if(dir == LEFT)
				j--;
			else
				j++;
			
		}
	}else{	//UP,DOWN
		for(int i = red.x; 0 <= i && i < n; ){
			if(maze[i][red.y] == 'O'){
				*flag_r = 1;
				red.x = i;
				break;
			}else if(maze[i][red.y] == '#' || (i == blue.x && red.y == blue.y)){
				if(dir == UP)
					red.x = i + 1;
				else
					red.x = i - 1;
				break;
			}
			if(dir == UP)
				i--;
			else
				i++;
			
		}
	}
//#ifdef DEBUG
//	printf("red x,y : %d, %d\n", red.x, red.y);
//#endif
}

int direction(int i, int j){
	int result = -1;
	if(i == 0){
		if(j < 0)
			result = LEFT;
		if(j > 0)
			result = RIGHT;
	}else if(j == 0){
		if(i > 0)
			result = DOWN;
		if(i < 0)
			result = UP;
	}
//#ifdef DEBUG
//	printf("tmp dir : %d\n", result);
//#endif
	return result;
}

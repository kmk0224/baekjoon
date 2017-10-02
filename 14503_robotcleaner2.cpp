#include <iostream>

using namespace std;

int n, m;
int **arr;
int nx[] = {-1, 0, 1, 0};
int ny[] = {0, -1, 0, 1};

bool checkAllDirection(int x, int y);

int main(){	
	int r, c, d; // 0 : 북쪽, 1 : 동쪽, 2 : 남쪽, 3 : 서쪽
	int count = 0;

	cin >> n >> m;
	cin >> r >> c >> d;

	//alloc arr
	arr = new int*[n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[m];
	}

	// input
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}

	while(true){
		// 현재위치 청소
		if(arr[r][c] == 0){
			arr[r][c] = 2;
			count++;
		}
		bool check = checkAllDirection(r, c);

		if(check){ // 주변에 빈칸이 있음
			int x = -1;

			if (d == 0)
				x = 1;
			else if(d == 1)
				x = 0;
			else if(d == 2)
				x = 3;
			else
				x = 2;

			for(int i = x; i < x + 4; i++){
				int dx = r + nx[i % 4];
				int dy = c + ny[i % 4];
				if(dx >= 0 && dx < n && dy >=0 && dy < m){
					if(arr[dx][dy] == 0){
						r = dx;
						c = dy;
						if(i % 4 == 0)
							d = 0;
						else if (i % 4 == 1)
							d = 3;
						else if (i % 4 == 2)
							d = 2;
						else
							d = 1;
						break;
					}
				}
			}
		} else{ // 주변에 빈칸이 없음
			if(d == 0 && r + 1 <  n){ //북
				if(arr[r + 1][c] == 1)
					break;
				else{
					r = r + 1;
				}
			}else if(d == 1 && c - 1 >= 0){ //동
				if(arr[r][c - 1] == 1)
					break;
				else{
					c = c - 1;
				}
			}else if(d == 2 && r - 1 >= 0){//남
				if(arr[r - 1][c] == 1)
					break;
				else{
					r = r - 1;
				}
			}else if(d == 3 && c + 1 >= 0){ //서
				if(arr[r][c + 1] == 1)
					break;
				else{
					c = c + 1;
				}
			}
		}
	}

	cout << count << endl;
	
	//free arr
	for(int i = 0; i < n; i++){
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}

bool checkAllDirection(int x, int y){
	bool result = false;
	for(int i = 0; i< 4; i++){
		int dx = x + nx[i];
		int dy = y + ny[i];
		if(dx >= 0 && dx < n && dy >=0 && dy < m){
			if(arr[dx][dy] == 0){
				result = true; // 0이 주변에 있음
				break;
			}
		}
	}
	return result;
}

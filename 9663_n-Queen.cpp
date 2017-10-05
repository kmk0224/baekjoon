#include <iostream>

using namespace std;

int n;
int ans = 0;
bool a[15][15] ={0, };

bool check(int row, int col);
void cal(int row);

int main(){
	cin >> n;
	cal(0);
	cout << ans << endl;
	return 0;
}

void cal(int row){
	if(row == n){
		ans++;
	}
	for(int i = 0; i < n; i++){
			a[row][i] = true;
			if(check(row, i)){
				cal(row + 1);
			}
			a[row][i] = false;
	}
}

bool check(int row, int col){
	//위, 아래 검사
	for(int i = 0; i < n; i++){
		if(i != row){
			if(a[i][col])
				return false;
		}
	}

	int x = row - 1;
	int y = col - 1;
	while(x >=0 && y >=0){
		if(a[x][y])
			return false;
		x -= 1;
		y -= 1;
	}

	x = row - 1;
	y = col + 1;
	while(x >= 0 && y < n){
		if(a[x][y] == true)
			return false;
		x -= 1;
		y += 1;
	}
//	//오른쪽 대각선(위)
//	for(int i = 1; i < n; i++){
//		if(row - i >= 0 && col + i < n){
//			if(a[row - i][col + i] == true)
//				return false;
//		}
//	}
//
//	//왼쪽 대각선(위)
//	for(int i = 1; i < n; i++){
//		if(row - i >= 0 && col - i >= n){
//			if(a[row - i][col - i] == true){
//				return false;
//			}
//		}
//	}
	return true;
}

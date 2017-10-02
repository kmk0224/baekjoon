#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n;
	int arr[100][100] = {0, };
	bool d[100][100] = {0, };

	cin >> n;

	queue< pair<int, int> > q;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1){
				q.push(make_pair(i, j));
				d[i][j] = true;
			}
		}
	}

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < n; i++){
			if(d[y][i] == true && d[x][i] == false){
				d[x][i] = true;
				q.push(make_pair(x, i));
			}
		}
	}


	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(d[i][j] == true){
				cout << "1 ";
			}
			else
				cout << "0 ";
		}
		cout << endl;
	}

	return 0;
}

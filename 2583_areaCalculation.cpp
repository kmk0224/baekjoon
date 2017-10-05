#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool field[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int area[100*100];

pair<int, int> check(int m, int n);

int main(){
	int m, n, k, count = 0;
	cin >> m >> n >> k;

	memset(field, false, sizeof(field));

	// k-relavant arr 
	int **arr = new int*[k];
	for(int i = 0; i < k; i++){
		arr[i] = new int[4];
	}

	// k-relavant arr input
	for(int i = 0; i < k; i++){
		for(int j = 0; j < 4; j++){
			cin >> arr[i][j];
			if(j == 2 || j == 3)
				arr[i][j] -= 1;
		}
		//cout << arr[i][0] << arr[i][1] << arr[i][2] << arr[i][3] << endl;
	}

	for(int i = 0; i < k; i++){
		int to_y =arr[i][0];
		int to_x = m - 1 - arr[i][1];
		int from_y = arr[i][2];
		int from_x = m - 1 - arr[i][3];
//		cout <<i<<": " <<to_x << to_y << from_x <<from_y<<endl;
		for(int j = 0; j < m; j++){
			for(int k = 0; k < n; k++){
				if(from_x <= j && j <= to_x
						&& to_y <= k && k <= from_y)
					field[j][k] =true;
			}
		}
	}

	while(true){
		int sub_count = 0;
		pair<int,int > tmp = check(m, n);
		if(tmp.first == -1 && tmp.second == -1)
			break;

		queue<pair<int, int> > q;
		q.push(tmp);
		field[tmp.first][tmp.second] = true;
		sub_count++;

		while(!q.empty()){
			pair<int, int> now = q.front();
			q.pop();

			for(int i = 0; i < 4; i++){
				int x = now.first + dx[i];
				int y = now.second + dy[i];
				if(x <  0 || x >= m || y < 0 || y >= n)
					continue;
				if(field[x][y] == false){
					q.push(make_pair(x, y));
					field[x][y] = true;
					sub_count++;
				}
			}
		}
		area[count] = sub_count;
		count++;
	}

	vector<int> v(area, area + count);
	sort(v.begin(), v.end());
	cout << count << endl;
	for(int i = 0; i < count ; i++)
		cout << v[i] << " ";
	cout << endl;

	// free k-relavant arr
	for(int i = 0; i < k; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}

pair<int, int> check(int m, int n){
	for(int i = 0;i < m; i++){
		for(int j = 0; j < n; j++){
			if(field[i][j] == false)
				return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}

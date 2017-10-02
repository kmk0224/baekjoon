//fail

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, k;
int arr[101][101] = {0, };
int check[10000] = {0, };
int **idx;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool checkAll();
pair<int, int> returnPair();

int main(){
	int count = 0;
	cin >> m >> n >> k;

	idx = new int*[k];
	for(int i = 0; i < k; i++)
		idx[i] = new int[4];

	for(int i = 0; i < k; i++)
		for(int j = 0; j < 4; j++)
			cin >> idx[i][j];


	for(int i = 0; i < k; i++){
		int from_x = idx[i][0];
		int from_y = idx[i][1];
		int to_x = idx[i][2];
		int to_y = idx[i][3];
		cout << from_x <<from_y << to_x << to_y <<endl;

		for(int j = 0; j <= m; j++){
			for(int z = 0; z <= n; z++){
				if(j >= from_x && j <= to_x && z >= from_x && z <= to_y){
					arr[j][z] = 1;
				}
			}
		}
	}

	for(int i = 0; i<=m; i++){
		for(int j = 0; j<=n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	while(!checkAll()){
		queue<pair<int, int> > q;
		q.push(returnPair());
		int value = 1;

		while(!q.empty()){
			int now_x = q.front().first;
			int now_y = q.front().second;
			q.pop();

			for(int i = 0; i < 4; i++){
				int nx = now_x + dx[i];
				int ny = now_y + dy[i];
				if(nx >= 0 && nx <=m && ny >=0 && ny <=n){
					if(arr[nx][ny] == 0){
						arr[nx][ny] = 1;
						q.push(make_pair(nx, ny));
						value++;
					}
				}
			}
		}

		for(int i = 0; i<=m; i++){
			for(int j = 0; j<=n; j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		check[count] = value;
		count++; //point next index
	}

	sort(check, check + count - 1);

	cout << count << endl;
	for(int i = 0; i < count; i++){
		cout << check[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < k; i++)
		delete[] idx[i];
	delete[] idx;

	return 0;
}

bool checkAll(){
	bool result = true;
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(arr[i][j] == 0){
				result = false;
				break;
			}
		}
	}
	return result;
}

pair<int, int> returnPair(){
	pair<int, int> result;

	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(arr[i][j] == 0){
				result.first = i;
				result.second = j;
				break;
			}
		}
	}
	return result;
}

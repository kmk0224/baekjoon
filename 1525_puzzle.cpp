#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
// 오른쪽, 왼쪽, 아래, 위

int main(){
	int start = 0;
	queue<int> q;
	map<int, int> d;

	for(int i = 0; i < 9; i++){	
		int tmp  = -1;
		cin >> tmp;
		if(tmp == 0)
			tmp = 9;
		start = start * 10 + tmp;
	}

	d[start] = 0;
	q.push(start);

	while(!q.empty()){
		int now = q.front();
		string s_now = to_string(now);
		q.pop();

		int z = s_now.find('9');
		int x = z / 3;
		int y = z % 3;

		for(int k = 0; k < 4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];

			if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
				string s_next = s_now;
				swap(s_next[x * 3 + y], s_next[nx * 3 + ny]);
				int next = stoi(s_next);

				if(d.count(next) == 0){
					q.push(next);
					d[next] = d[now] + 1;
				}

			}
		}
	}


	if(d.count(123456789) == 0){
		cout << -1 << endl;
	}else{
		cout << d[123456789] << endl;
	}

	return 0;
}

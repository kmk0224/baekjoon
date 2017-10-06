#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

string input[64 * 64 * 64];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
	int n, m;
	int field[8][8];
	int cnt_input = 0; //next index
	int max = 0;

	//input
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> field[i][j];
		}
	}

	for(int i1 = 0; i1 < n; i1++){
		for(int j1 = 0; j1 < m; j1++){
			if(field[i1][j1] != 0)
			continue;
			for(int i2 = 0; i2 < n; i2++){
				for(int j2 = 0; j2 < m; j2++){
					if(field[i2][j2] != 0)
					continue;
					for(int i3 = 0; i3 < n; i3++){
						for(int j3 = 0; j3 < m; j3++){
							if(field[i3][j3] != 0)
							continue;
							if((i1 == i2 && j1 == j2)
							|| (i2 == i3 && j2 == j3)
							|| (i3 == i1 && j3 == j1))
								continue;
							string tmp = to_string(i1) + to_string(j1)
								+ to_string(i2) + to_string(j2)
								+ to_string(i3) + to_string(j3);
							input[cnt_input] = tmp;
							cnt_input++;
						}
					}
				}
			}
		}
	}

	int i = 0;
	while(i < cnt_input){
		//copy field
		int now_field[8][8];
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				now_field[j][k] = field[j][k];
			}
		}

		// build wall when there is no virus or wall (1, 2)
		string tmp = input[i];
		int num_tmp = stoi(tmp);
//		cout << num_tmp << endl;

		for(int j = 0; j < 3; j++){
			int k = num_tmp % 100;
			if(k == 0){
				if(now_field[0][0] == 0)
					now_field[0][0] = 1;
			}else{
				if(now_field[k/10][k%10] == 0)
					now_field[k/10][k%10] = 1;
				
			}
			num_tmp /= 100;
		}

		// enqueue the virus (2)
		queue<pair<int, int> > now_q;

		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(now_field[j][k] == 2)
					now_q.push(make_pair(j, k));
			}
		}

		while(!now_q.empty()){
			int x = now_q.front().first;
			int y = now_q.front().second;
			now_q.pop();

			for(int j = 0; j < 4; j++){ // 네방향에 대해서
				int next_x = x + dx[j];
				int next_y = y + dy[j];
				if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) //범위밖의 바이러스
					continue;
				if(now_field[next_x][next_y] == 0){
					now_field[next_x][next_y] = 2;
					now_q.push(make_pair(next_x, next_y));
				}
			}
		}

		int tmp_cnt = 0;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(now_field[j][k] == 0)
					tmp_cnt++;
			}
		}

		if(tmp_cnt > max){
			max = tmp_cnt;
		}
		i++;
	}

	cout << max << endl;
	return 0;
}

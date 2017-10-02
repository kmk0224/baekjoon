#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

bool prime[10000]; //초기화 false
int dist[10000];
bool check[10000];

int change(int x, int index, int i);

int main(){
	int t, a, b;

	// 소수 구하기
	for(int i = 2; i < 10000; i++){
		if(prime[i] == false){
			for(int j = i * i ; j < 10000; j +=i){
				prime[j] = true;
			}
		}
	}

	for(int i = 0; i < 10000; i++){
		prime[i] = !prime[i];
	}

	cin >> t;

	for(int i = 0; i < t; i++){
		// 초기화
		memset(dist, -1, sizeof(int) * 10000);
		memset(check, false, sizeof(bool) * 10000);
		cin >> a >> b;

		queue<int> q;
		q.push(a);
		dist[a] = 0;
		check[a] = true;

		while(!q.empty()){
			int tmp = q.front();
			q.pop();

			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 10; k++){
					int next = change(tmp, j, k);
					if(next != -1 && check[next] == false && prime[next]){
						check[next] = true;
						dist[next] = dist[tmp] + 1;
						q.push(next);
					}
				}
			}
		}

		if(check[b] == false)
			cout << "Impossible" << endl;
		else
			cout << dist[b] << endl;
	}
	return 0;
}

int change(int x, int index, int i){
	int result = -1;
	if(index == 0 && i == 0)
		return result;
	string str = to_string(x);
	str[index] = i + '0';
	result = stoi(str);
	return result;
}

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define max 200000
bool check[max + 1];
int dist[max + 1];

int main(){
	int n, k;

	for(int i = 0; i < max; i++){
		dist[i] = -1;
		check[i] = false;
	}
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	check[n] = true;

	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		if(tmp-1 >= 0){
			if(check[tmp - 1] == false){
				q.push(tmp - 1);
				check[tmp - 1] = true;
				dist[tmp - 1] = dist[tmp] + 1;
			}
		}
		if(tmp + 1 < max){
			if(check[tmp + 1] == false){
				q.push(tmp + 1);
				check[tmp + 1] = true;
				dist[tmp + 1] = dist[tmp] + 1;
			}
		}
		if(tmp *2 < max){
			if(check[tmp * 2] == false){
				q.push(tmp * 2);
				check[tmp * 2] = true;
				dist[tmp * 2] = dist[tmp] + 1;
			}
		}
	}

	cout << dist[k] << endl;
	return 0;
}

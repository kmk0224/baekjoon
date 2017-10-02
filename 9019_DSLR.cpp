#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int dist[10000];
int from[10000];
char how[10000];
bool check[10000];

int main(){
	int t, a, b;

	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b;
		memset(dist, -1, sizeof(int) * 10000);
		memset(from, 0, sizeof(int) * 10000);
		memset(how, 0, sizeof(char) * 10000);
		memset(check, false, sizeof(bool) * 10000);

		dist[a] = 0;
		from[a] = -1;
		check[a] = true;
		queue<int> q;
		q.push(a);

		while(!q.empty()){
			int now = q.front();
			q.pop();
			// D
			int next = (now * 2) % 10000;
			if(check[next] == false){
				from[next] = now;
				how[next] = 'D';
				dist[next] = dist[now] + 1;
				check[next] = true;
				q.push(next);
			}
			// S
			next = now - 1;
			if(next == -1)
				next = 9999;
			if(check[next] == false){
				from[next] = now;
				how[next] = 'S';
				dist[next] = dist[now] + 1;
				check[next] = true;
				q.push(next);
			}
			// L
			next = (now%1000)*10 + now/1000;
			if(check[next] == false){
				from[next] = now;
				how[next] = 'L';
				dist[next] = dist[now] + 1;
				check[next] = true;
				q.push(next);
			}
			// R
			next = (now%10)*1000 + now/10;
			if(check[next] == false){
				from[next] = now;
				how[next] = 'R';
				dist[next] = dist[now] + 1;
				check[next] = true;
				q.push(next);
			}
			//cout << "R\n";
		}
		//cout <<"END!!!!!!!!!!!!!!"<<endl;
		string ans = "";
		while(a != b){
			ans += how[b];
			b = from[b];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}

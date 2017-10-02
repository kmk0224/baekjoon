#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	bool C[201]; // 0 ~ 201
	bool AB[201][201]; 
	int a, b, c;
	queue< pair<int, int> > q;

	cin >> a >> b >> c;
	memset(C, false, sizeof(C));
	memset(AB, false, sizeof(AB));

	AB[0][0] = 1;
	C[c] = 1;

	q.push(make_pair(0, 0));

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int z = c - x - y;
		q.pop();
		int nx = x, ny = y, nz = z;

		//a -> b
		ny += nx;
		nx = 0;
		if(ny > b){
			nx = ny - b;
			ny = b;
		}
		if(!AB[nx][ny]){
			q.push(make_pair(nx, ny));
			AB[nx][ny] = true;
			if(nx == 0)
				C[nz] = true;
		}

		//a -> c
		nx = x, ny = y, nz = z;
		
		nz += nx;
		nx = 0;
		if(nz > c){
			nx = nz - c;
			nz = c;
		}
		if(!AB[nx][ny]){
			q.push(make_pair(nx, ny));
			AB[nx][ny] = true;
			if(nx == 0)
				C[nz] = true;
		}

		//b -> a
		nx = x, ny = y, nz = z;
		nx += ny;
		ny = 0;
		if(nx > a){
			ny = nx - a;
			nx = a;
		}
		if(!AB[nx][ny]){
			q.push(make_pair(nx, ny));
			AB[nx][ny] = true;
			if(nx == 0)
				C[nz] = true;
		}

		//b -> c
		nx = x, ny = y, nz = z;
		nz += ny;
		ny = 0;
		if(nz > c){
			ny = nz - c;
			nz = c;
		}
		if(!AB[nx][ny]){
			q.push(make_pair(nx, ny));
			AB[nx][ny] = true;
			if(nx == 0)
				C[nz] = true;
		}

		//c -> a
		nx = x, ny = y, nz = z;
		nx += nz;
		nz = 0;
		if(nx > a){
			nz = nx - a;
			nx = a;
		}
		if(!AB[nx][ny]){
			q.push(make_pair(nx, ny));
			AB[nx][ny] = true;
			if(nx == 0)
				C[nz] = true;
		}


		//c -> b
		nx = x, ny = y, nz = z;
		ny += nz;
		nz = 0;
		if(ny > b){
			nz = ny - b;
			ny = b;
		}
		if(!AB[nx][ny]){
			q.push(make_pair(nx, ny));
			AB[nx][ny] = true;
			if(nx == 0)
				C[nz] = true;
		}
	}

	for(int i = 0; i <= c; i++){
		if(C[i] == true)
			cout << i << " ";
	}
	cout << endl;

	return 0;
}

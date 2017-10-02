#include <iostream>
#include <cstdio>

using namespace std;

bool broken[10]; // 버튼이 망가져있으면 true, 아니면 false
int possible(int c){
	if(c == 0){
		if(broken[0])
			return 0;
		else
			return 1;
	}
	int len = 0;
	while(c > 0){
		if(broken[c % 10])
			return 0;
		len++;
		c = c/10;
	}
	return len;
}

int main(){
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		broken[x] = true;
	}

	// 현재 채널에서 +나 -로만으로 이동한 수 (MAX)
	int ans = n - 100; // n >= 100
	if(ans < 0) // n < 100
		ans = -ans;

	for(int i = 0; i <= 1000000; i++){ // 숫자버튼으로 이동하려는 채널
		int c = i;
		int len = possible(c);
		if(len > 0){
			int press = c - n;
			if(press < 0)
				press = -press;

			if(ans > press + len){
				ans = press + len;
			}

		}
	}

	printf("%d\n", ans);
	return 0;
}

#include <iostream>

using namespace std;

int main(){
	int E = 0, S = 0, M = 0;
	cin >> E >> S >> M;

	int e = 1, s = 1, m = 1;

	for(int i = 1; ; i++){
		if(e == E && s == S && m == M){
			cout << i << '\n';
			break;
		}
		else{
			if(e == 15)
				e = 1;
			else
				e++;

			if(s == 28)
				s = 1;
			else
				s++;

			if(m == 19)
				m = 1;
			else
				m++;
		}
	}


	return 0;
}

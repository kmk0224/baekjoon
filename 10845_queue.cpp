#include <iostream>
#include <string>
#define max 10000

using namespace std;

int main(){
	int n = 0;
	cin >> n;
	int queue[10000] = {0, };
	int head = 0;
	int rear = 0;
	int cnt = 0;

	while(n > 0){
		string cmd;
		int sub = -1;
		cin >> cmd;
		if(cmd == "push"){
//			cout << "push" << endl;
			cin >> sub;
			queue[(rear++) % max] = sub;
			cnt++;
		}else if(cmd == "front"){
//			cout << "front" << endl;
			if(cnt > 0)
				cout << queue[head] << endl;
			else
				cout << -1 << endl;
		}else if(cmd == "back"){
//			cout << "back" << endl;
			if(cnt > 0){
				if(rear - 1 == -1)
					cout << queue[max -1] << endl;
				else
					cout << queue[rear -1] << endl;
			}else
				cout << -1 << endl;
		}else if(cmd == "size"){
//			cout << "size" << endl;
			cout << cnt << endl;
		}else if(cmd == "empty"){
//			cout << "empty" << endl;
			if(cnt > 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}else if(cmd == "pop"){
//			cout << "pop" << endl;
			if(cnt <= 0)
				cout << -1 << endl;
			else{
				queue[head] = 0;
				head = (head + 1) % max;
				cnt--;
			}
		}
		n--;
	}
	return 0;
}

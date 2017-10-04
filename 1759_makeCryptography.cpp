//fail
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int l, c;
bool check(string s){
	int a = 0;
	int b = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
		|| s[i] == 'o' || s[i] =='u')
			a++;
		else
			b++;
	}
	if(a >=1 && b>=2)
		return true;
	return false;
}

void go(int n, char* c_arr, string password, int index){
	if(password.length() == n){
		if(check(password)){
			cout << password << endl;
		}
		return;
	}
	if(index >= c)
		return;
	go(n, c_arr, password + c_arr[index], index + 1);
	go(n, c_arr, password, index + 1);
}


int main(){
	char * c_arr;

	cin >> l >> c;

	c_arr = new char[c];
	for(int i = 0; i < c; i++)
		cin >> c_arr[i];
	sort(c_arr, c_arr + c - 1);

	go(l, c_arr, "", 0);
	delete[] c_arr;
	return 0;
}

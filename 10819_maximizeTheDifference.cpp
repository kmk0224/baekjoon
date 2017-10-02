#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculate(vector<int> &a);
int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;

	do{
		int tmp = calculate(a);
		ans = max(tmp, ans);

	}while(next_permutation(a.begin(), a.end()));

	printf("%d\n", ans);
	return 0;
}

int calculate(vector<int> &a){
	int sum = 0;
	for(int i = 1; i < a.size(); i++){
		sum += abs(a[i] - a[i-1]);
	}
	return sum;
}

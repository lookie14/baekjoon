#include<iostream>
#include<vector>
using namespace std;
vector<long long> arr;
int main() {
	arr.push_back(0);
	arr.push_back(1);
	int n;
	cin >> n;
	for (int i = 0; i <= n - 1; i++) {
		arr.push_back(arr[i] + arr[i + 1]);
	}
	cout << arr[n];
	return 0;
}
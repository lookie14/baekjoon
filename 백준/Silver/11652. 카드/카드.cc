#include<iostream>
#include<algorithm>
using namespace std;
long long arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans;
	int count = 1, max = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ans = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) {
			count++;
		}
		else {
			count = 1;
		}
		if (max < count) {
			ans = arr[i];
			max = count;
		}
	}
	cout << ans;
	return 0;
}
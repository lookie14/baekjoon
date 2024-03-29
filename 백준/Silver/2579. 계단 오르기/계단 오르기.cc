#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[301], dp[301];
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	if (N <= 2) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += arr[i];
		}
		cout << sum;
	}
	else {
		dp[0] = 0;
		dp[1] = arr[1];
		dp[2] = arr[1] + arr[2];
		for (int i = 3; i <= N; i++) {
			dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		}
		cout << dp[N];
	}
	
	return 0;
}
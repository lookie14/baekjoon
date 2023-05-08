#include<iostream>
using namespace std;
int N;
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[N];
	return 0;
}
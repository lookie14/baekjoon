#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, cnt = 0;
	cin >> N;
	int sum, tmp;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		tmp = i;
		while (sum < N) {
			sum += tmp;
			tmp++;
		}
		if (sum == N)cnt++;
	}
	cout << cnt;
	return 0;
}
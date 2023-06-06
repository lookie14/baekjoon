#include<iostream>
int arr[301][301];
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, T;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> T;
	while (T--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int sum = 0;
		for (int k = i; k <= x; k++) {
			for (int l = j; l <= y; l++) {
				sum += arr[k][l];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}

#include<iostream>

using namespace std;

int N, M;
int arr[501][501];
int ans = 0;

int max(int a, int b) {
	if (a >= b)return a;
	else return b;
}

int min(int a, int b) {
	if (a < b)return a;
	else return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N-1; i++) {        // case 1(2*3)
		for (int j = 0; j < M-2; j++) {
			int sum = 0;
			int tmp = 2000;
			for (int n = 0; n < 2; n++) {
				for (int m = 0 ; m < 3; m++) {
					sum += arr[i + n][j + m];
				}
			}
			tmp = min(tmp, arr[i][j] + arr[i][j + 2]);
			tmp = min(tmp, arr[i + 1][j] + arr[i + 1][j + 2]);
			tmp = min(tmp, arr[i][j + 1] + arr[i][j + 2]);
			tmp = min(tmp, arr[i + 1][j + 1] + arr[i + 1][j + 2]);
			tmp = min(tmp, arr[i][j] + arr[i][j + 1]);
			tmp = min(tmp, arr[i + 1][j] + arr[i + 1][j + 1]);
			tmp = min(tmp, arr[i][j] + arr[i + 1][j + 2]);
			tmp = min(tmp, arr[i + 1][j] + arr[i][j + 2]);
			ans = max(ans, sum - tmp);
		}
	}

	for (int i = 0; i < N - 2; i++) {      //case 2(3*2)
		for (int j = 0; j < M - 1; j++) {
			int sum = 0;
			int tmp = 2000;
			for (int n = 0; n < 3; n++) {
				for (int m = 0; m < 2; m++) {
					sum += arr[i + n][j + m];
				}
			}
			tmp = min(tmp, arr[i][j + 1] + arr[i + 2][j + 1]);
			tmp = min(tmp, arr[i][j] + arr[i + 2][j]);
			tmp = min(tmp, arr[i][j + 1] + arr[i + 1][j + 1]);
			tmp = min(tmp, arr[i][j] + arr[i + 1][j]);
			tmp = min(tmp, arr[i + 1][j + 1] + arr[i + 2][j + 1]);
			tmp = min(tmp, arr[i + 1][j] + arr[i + 2][j]);
			tmp = min(tmp, arr[i][j] + arr[i + 2][j + 1]);
			tmp = min(tmp, arr[i][j + 1] + arr[i + 2][j]);
			ans = max(ans, sum - tmp);
		}
	}

	for (int i = 0; i < N ; i++) {    //case 3 (1*4)
		for (int j = 0; j < M - 3; j++) {
			ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
		}
	}

	for (int i = 0; i < N - 3; i++) {     //case 4(4*1)
		for (int j = 0; j < M; j++) {
			ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
		}
	}

	for (int i = 0; i < N - 1; i++) {    //case 5(2*2)
		for (int j = 0; j < M - 1; j++) {
			ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
		}
	}

	cout << ans;

	return 0;
}
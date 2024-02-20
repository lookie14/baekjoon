#include<iostream>

using namespace std;

int T;
int M, N, x, y;

int lcm(int a, int b) {
	int A = a;
	int B = b;
	while (B != 0) {
		int r = A % B;
		A = B;
		B = r;
	}
	return a * b / A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	while (T--) {
		int result = -1;
		cin >> M >> N >> x >> y;
		int maxi = lcm(M, N);
		for (int i = x; i <= maxi; i += M) {
			int ny = i % N;
			if (ny == 0)ny = N;
			if (ny == y) {
				result = i;
				break;
			}
		}
		cout << result << "\n";
	}
	

	return 0;
}
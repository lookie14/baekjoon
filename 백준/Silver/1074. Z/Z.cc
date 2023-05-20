#include<iostream>
#include<math.h>
using namespace std;
int split(int size, int row, int col) {
	if (size == 0) return 0;
	int n_row = row, n_col = col;
	int n = size;
	int count = 0;
	int state = 0;
	if (pow(2, n-1) <= row) {
		count += (2*pow(pow(2, n - 1),2));
		n_row = row - pow(2, n - 1);
	}
	if (pow(2, n - 1) <= col) {
		count += (pow(pow(2, n - 1), 2));
		n_col = col - pow(2, n - 1);
	}
	count += split(n - 1, n_row, n_col);
	return count;
}
int N, r, c;
int ss = pow(2, N);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> r >> c;
	cout << split(N, r, c);
	return 0;
}

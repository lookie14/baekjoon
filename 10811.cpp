#include<iostream>
using namespace std;

int main() {
	int arr[100];
	for (int k = 0; k < 100; k++) arr[k] = k + 1;
	int N, M;
	int i, j, blank;
	cin >> N >> M;
	for (int k = 0; k < M; k++) {
		cin >> i >> j;
		while (i < j) {
			blank = arr[i - 1];
			arr[i - 1] = arr[j - 1];
			arr[j - 1] = blank;
			i++;
			j--;
		}
	}
	for (int k = 0; k < N; k++) cout << arr[k] << " ";
	return 0;
}
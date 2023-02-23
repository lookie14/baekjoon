#include<iostream>
using namespace std;

int main() {
	int arr[100];
	for (int i = 0; i < 100; i++) arr[i] = i + 1;
	int N, M;
	int j, k, blank;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> j >> k;
		blank = arr[j - 1];
		arr[j - 1] = arr[k - 1];
		arr[k - 1] = blank;
	}
	for (int i = 0; i < N; i++)cout << arr[i] << " ";
	return 0;
}
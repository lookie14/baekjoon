#include<iostream>
using namespace std;

int main() {
	int arr[100] = { 0, };
	int N, M;
	int i, j, k;
	cin >> N >> M;
	for (int q = 0; q < M; q++) {
		cin >> i >> j >> k;
		while(i<=j){
			arr[i - 1] = k;
			i++;
		}
	}
	for (int q = 0; q < N; q++) {
		cout << arr[q] << " ";
	}
	return 0;
}
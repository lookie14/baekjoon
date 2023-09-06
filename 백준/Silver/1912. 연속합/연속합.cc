#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i == 0) {
			arr[i] = tmp;
			continue;
		}
		if (arr[i - 1] >0 && tmp >= 0) arr[i] = arr[i - 1] + tmp;
		else if(tmp <0 && arr[i-1] + tmp >0 ) arr[i] = arr[i - 1] + tmp;
		else arr[i] = tmp;
	}
	cout << *max_element(arr, arr + N);
	return 0;
}

#include<iostream>

using namespace std;

int arr[10] = { 0 };
int main() {
	int N, cnt = 0;
	cin >> N;
	while (N > 0) {
		arr[N % 10] ++;
		N /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)continue;
		if (arr[i] > cnt) cnt = arr[i];
	}
	int sum = arr[6] + arr[9];
	if (sum % 2 == 1) {
		if ((sum + 1) / 2 > cnt)cnt = (sum + 1) / 2;
	}
	else {
		if (sum / 2 > cnt)cnt = sum / 2;
	}
	cout << cnt;
	return 0;
}
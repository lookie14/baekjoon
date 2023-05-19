#include<iostream>
#include<algorithm>
using namespace std;
int arr[9];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = -100;
	int flag = 0;
	int num1;
	int num2;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == sum) {
				num1 = i;
				num2 = j;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	for (int i = 0; i < 9; i++) {
		if (i == num1 || i == num2) {
			continue;
		}
		cout << arr[i] << "\n";
	}
	return 0;
}

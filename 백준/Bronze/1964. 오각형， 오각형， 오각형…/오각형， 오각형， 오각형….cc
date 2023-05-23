#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int sum = 5;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		sum += (3 * i + 1);
		sum = sum % 45678;
	}
	cout << sum;
	return 0;
}
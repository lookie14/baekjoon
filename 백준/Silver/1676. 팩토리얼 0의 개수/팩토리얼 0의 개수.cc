#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int count = 0;
	n -= (n % 5);
	while (n > 0) {
		int tmp = n;
		while (tmp%5==0) {
			tmp /= 5;
			count++;
		}
		n -= 5;
	}
	cout << count;
	return 0;
}
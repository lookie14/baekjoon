#include<iostream>
#include<math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int X;
	int count = 0;
	cin >> X;
	for (int i = 6; i >= 0; i--) {
		if (pow(2, i) <= X) {
			X -= pow(2, i);
			count++;
		}
		if (X == 0)break;
	}
	cout << count;
	return 0;
}

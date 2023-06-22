#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int T,N;
	int n;
	int tmp;
	cin >> T;
	while (T--) {
		n = 0;
		cin >> N;
		tmp = N;
		while (tmp > 0) {
			tmp /= 10;
			n++;
		}
		tmp = N * N;
		if (tmp % int(pow(10,n)) == N)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
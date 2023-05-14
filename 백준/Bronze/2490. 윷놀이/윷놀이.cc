#include<iostream>
using namespace std;

int main() {
	int T = 3;
	int n;
	while (T--) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			cin >> n;
			sum += n;
		}
		if (sum == 0)cout << "D" << "\n";
		else if (sum == 1) cout << "C" << "\n";
		else if (sum == 2) cout << "B" << "\n";
		else if (sum == 3) cout << "A" << "\n";
		else cout << "E" << "\n";
	}
	return 0;
}
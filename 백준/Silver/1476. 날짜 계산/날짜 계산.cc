#include<iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int E, S, M;
	int e =0, s=0, m=0;
	int year = 0;
	cin >> E >> S >> M;
	while (E != e || S != s || M != m) {
		e++;
		s++;
		year++;
		m++;
		if (e > 15)e -= 15;
		if (s > 28)s -= 28;
		if (m > 19)m -= 19;
	}
	cout << year;
	return 0;
}

#include<iostream>
using namespace std;

int gcd(int a, int b) {
	int mod = a % b;
	while (mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, a2;
	int b1, b2;
	int r1, r2;
	cin >> a1 >> a2 >> b1 >> b2;
	r1 = b2 * a1 + a2 * b1;
	r2 = a2 * b2;
	int div;
	if (r1 >= r2) {
		div = gcd(r1, r2);
	}
	else div = gcd(r2, r1);
	cout << r1 / div << " " << r2 / div;
	return 0;
}

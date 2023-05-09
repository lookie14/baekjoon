#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a;
	cin >> a;
	int num1, num2;
	int flag = 0;
	for (int i = 1; i < a.size(); i++) {
		num1 = 1;
		num2 = 1;
		for (int j = 0; j < i; j++) {
			num1 *= (a.at(j)-'0');
		}
		for (int j = i; j < a.size(); j++) {
			num2 *= (a.at(j)-'0');
		}
		if (num1 == num2) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		cout << "YES";
	}
	else cout << "NO";
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main() {
	long long sum = 0;;
	string N,M;
	cin >> N >> M;
	for (int i = 0; i < N.size(); i++) {
		for (int j = 0; j < M.size(); j++) {
			sum += (int(N.at(i))-'0') * (int(M.at(j))-'0');
		}
	}
	cout << sum;
	return 0;
}
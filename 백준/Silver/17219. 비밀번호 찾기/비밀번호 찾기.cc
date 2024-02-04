#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, string> Dict;
int N, M;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	string a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		Dict[a] = b;
	}
	for (int i = 0; i < M; i++) {
		cin >> a;
		cout << Dict[a] << "\n";
	}

	return 0;
}
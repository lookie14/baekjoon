#include<iostream>
#include<map>
#include<string>
using namespace std;
int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int n; cin >> n;
		map<string, int> arr;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (arr.find(b) == arr.end()) {
				arr[b] = 1;
			}
			else {
				arr[b] ++;
			}
		}
		int ans = 1;
		int sum = 0;
		for (auto p : arr) {
			ans *= (p.second+1);
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}
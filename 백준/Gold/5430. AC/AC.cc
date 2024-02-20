#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
using namespace std;

int T, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		string p, str;
		deque<int> dq;
		bool rev = false, error = false;
		cin >> p;
		cin >> n;
		cin >> str;
		string s = "";
		for (int i = 0; i < str.length(); i++) {
			if (isdigit(str[i])) {
				s += str[i];
			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}
		for (auto f : p) {
			if (f == 'R') {
				if (rev)
					rev = false;
				else
					rev = true;
			}
			else {
				if (dq.empty()) {
					cout << "error" << "\n";
					error = true;
					break;
				}
				if (rev)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if (!error) {
			cout << '[';
		}
		if (rev && !dq.empty()) {
			for (auto o = dq.rbegin(); o != dq.rend(); o++) {
				if (o == dq.rend() - 1)
					cout << *o;
				else
					cout << *o << ',';
			}
		}
		else if (!rev && !dq.empty()) {
			for (auto o = dq.begin(); o != dq.end(); o++) {
				if (o == dq.end() - 1)
					cout << *o;
				else
					cout << *o << ',';
			}
		}
		if (!error)
			cout << "]\n";
	}
	return 0;
}
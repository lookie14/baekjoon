#include<iostream>
#include<queue>
using namespace std;
int N;
priority_queue<int> p_queue;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if(tmp == 0){
			if (p_queue.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << p_queue.top() << "\n";
				p_queue.pop();
			}
		}
		else {
			p_queue.push(tmp);
		}
	}

	return 0;
}
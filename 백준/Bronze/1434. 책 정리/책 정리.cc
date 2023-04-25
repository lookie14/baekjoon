#include<iostream>
#include<queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int book[51];
	queue<int> box;
	int N, M;
	int tmp;
	int bs = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		box.push(tmp);
	}
	int seq = 0;
	for (int i = 0; i < M; i++) cin >> book[i];
	while (box.size() != 0) {
		if (seq < M) {
			if (box.front() >= book[seq]) {
				box.front() -= book[seq];
				seq++;
				continue;
			}
		}
		bs += box.front();
		box.pop();
	}
	cout << bs;
	return 0;
}
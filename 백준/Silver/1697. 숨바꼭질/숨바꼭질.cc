#include<iostream>
#include<queue>
using namespace std;

int N, K;
bool visit[100001];

void bfs(int a) {
	queue<pair<int, int>> arr;
	arr.push(make_pair(a, 0));
	while (!arr.empty()) {
		int x = arr.front().first;
		int cnt = arr.front().second;
		arr.pop();
		if (x == K) {
			cout << cnt;
			break;
		}
		if (x + 1 >= 0 && x + 1 < 100001) {
			if (!visit[x + 1]) {
				visit[x + 1] = true;
				arr.push(make_pair(x + 1, cnt + 1));
			}
		}
		if (x - 1 >= 0 && x - 1 < 100001) {
			if (!visit[x - 1]) {
				visit[x - 1] = true;
				arr.push(make_pair(x - 1, cnt + 1));
			}
		}
		if (2*x >= 0 && 2*x  < 100001) {
			if (!visit[2*x]) {
				visit[2*x] = true;
				arr.push(make_pair(2*x, cnt + 1));
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	visit[N] = true;
	bfs(N);
	return 0;
}

#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
int N, M;

int arr[101][101];
bool visit[101][101] = { false, };
int dist[101][101] = { 0, };

int x_dir[4] = { -1, 1, 0, 0 };
int y_dir[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> Q;

void bfs(int sy, int sx) {
	visit[sy][sx] = true;
	Q.push(make_pair(sy, sx));
	dist[sy][sx] ++;
	while (! Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int x_new = x + x_dir[i];
			int y_new = y + y_dir[i];
			if ((0 < x_new && x_new <= M) && (0 < y_new && y_new <= N) && (!visit[y_new][x_new]) && (arr[y_new][x_new] == 1)) {
				visit[y_new][x_new] = true;
				Q.push(make_pair(y_new, x_new));
				dist[y_new][x_new] = dist[y][x] + 1;
			}
		}

	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string A; cin >> A;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = A[j-1] - '0';
		}
	}
	
	bfs(1,1);
	
	cout << dist[N][M];
	return 0;
}
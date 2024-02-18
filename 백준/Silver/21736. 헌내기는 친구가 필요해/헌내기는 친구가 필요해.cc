#include<iostream>
#include<string>
#include<queue>
using namespace std;

int N, M;
int s_x, s_y;
int ans = 0;
int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,1,-1 };
char arr[601][601];
bool visit[601][601] = { false, };
queue<pair<int, int>> Q;

void bfs(int xx, int yy) {
	visit[xx][yy] = true;
	Q.push(make_pair(xx, yy));
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];
			if (0 <= new_x && new_x < N && 0 <= new_y && new_y < M && !visit[new_x][new_y] && (arr[new_x][new_y] == 'O' || arr[new_x][new_y] == 'P')) {
				if (arr[new_x][new_y] == 'P')ans++;
				visit[new_x][new_y] = true;
				Q.push(make_pair(new_x, new_y));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				s_x = i;
				s_y = j;
			}
		}
	}

	bfs(s_x, s_y);

	if (ans == 0) cout << "TT";
	else cout << ans;

	return 0;
}
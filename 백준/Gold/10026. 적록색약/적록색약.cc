#include<iostream>
#include<queue>
using namespace std;

int N;
int ans1 = 0;
int ans2 = 0;
char arr[101][101];
bool visit1[101][101] = { false, };
bool visit2[101][101] = { false, };
queue<pair<int, int>> Q;
int dir_x[4] = { 1,-1,0,0 };
int dir_y[4] = { 0,0,1,-1 };

void bfs(int s_x, int s_y) {
	ans1++;
	char color = arr[s_x][s_y];
	Q.push(make_pair(s_x, s_y));
	visit1[s_x][s_y] = true;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];
			if (0 <= new_x < N && 0 <= new_y < N && !visit1[new_x][new_y] && arr[new_x][new_y] == color) {
				visit1[new_x][new_y] = true;
				Q.push(make_pair(new_x, new_y));
			}

		}

	}
}

void bfs2(int s_x, int s_y) {
	ans2++;
	char color = arr[s_x][s_y];

	Q.push(make_pair(s_x, s_y));
	visit2[s_x][s_y] = true;

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		if (color == 'R' || color == 'G') {
			for (int i = 0; i < 4; i++) {
				int new_x = x + dir_x[i];
				int new_y = y + dir_y[i];
				if (0 <= new_x < N && 0 <= new_y < N && !visit2[new_x][new_y] && (arr[new_x][new_y] == 'G' || arr[new_x][new_y] == 'R')) {
					visit2[new_x][new_y] = true;
					Q.push(make_pair(new_x, new_y));
				}

			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int new_x = x + dir_x[i];
				int new_y = y + dir_y[i];
				if (0 <= new_x < N && 0 <= new_y < N && !visit2[new_x][new_y] && arr[new_x][new_y] == color) {
					visit2[new_x][new_y] = true;
					Q.push(make_pair(new_x, new_y));
				}

			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit1[i][j]) bfs(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit2[i][j]) bfs2(i, j);
		}
	}

	cout << ans1 << " " << ans2;
	return 0;
}
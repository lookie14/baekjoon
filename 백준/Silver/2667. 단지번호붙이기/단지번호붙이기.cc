#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, M;
int arr[26][26];
bool visit[26][26] = {false, };
int dir_x[4] = { 1, -1, 0, 0 };
int dir_y[4] = { 0, 0, 1, -1 };
vector<int> ans;

queue<pair<int, int>> Q;

void bfs(int start_x, int start_y) {
	int cnt = 0;
	visit[start_x][start_y] = true;
	Q.push(make_pair(start_x, start_y));
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];
			if (0 <= new_x < N && 0 <= new_y < M && arr[new_x][new_y] == 1 && !visit[new_x][new_y]) {
				Q.push(make_pair(new_x, new_y));
				visit[new_x][new_y] = true;
			}
		}
	}
	ans.push_back(cnt);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		M = S.size();
		for (int j = 0; j < S.size(); j++) {
			arr[i][j] = int(S[j]) - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && !visit[i][j]) {
				bfs(i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
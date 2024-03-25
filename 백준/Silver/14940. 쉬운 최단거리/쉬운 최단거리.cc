#include<iostream>
#include<queue>
using namespace std;

int arr[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> Q;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int s_x, int s_y) {
    Q.push(make_pair(s_x, s_y));
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m && arr[new_x][new_y] && dist[new_x][new_y] == 0) {
                dist[new_x][new_y] = dist[x][y] + 1;
                Q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int r_x, r_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dist[i][j] = 0;
            if (arr[i][j] == 2) {
                r_x = i;
                r_y = j;
            }
        }
    }

    bfs(r_x, r_y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && dist[i][j] == 0) dist[i][j] = -1;
        }
    }

    dist[r_x][r_y] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
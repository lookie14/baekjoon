#include<iostream>
#include<queue>
using namespace std;

int N, M, K;
int s_x, s_y;
int arr[2002][2002];
int dist[2002][2002];
queue<pair<int, int>> Q;
queue<pair<int, int>> Q2;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void Ma() {
    int count = 0;
    while (!Q2.empty()) {

        if (count == K)return;
        count++;

        int cnt = Q2.size();
        for (int i = 0; i < cnt; i++) {
            int x = Q2.front().first;
            int y = Q2.front().second;
            Q2.pop();
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] != 3) {
                    arr[nx][ny] = 3;
                    Q2.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int bfs(int sx, int sy) {
    Q.push(make_pair(sx, sy));
    dist[sx][sy] = 0;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && dist[nx][ny] == -1 && (arr[nx][ny] != 1 && arr[nx][ny]!= 3)) {
                dist[nx][ny] = dist[x][y] + 1;
                if (arr[nx][ny] == 2) return dist[nx][ny];
                Q.push(make_pair(nx, ny));
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            dist[i][j] = -1;
            if (arr[i][j] == 4) {
                s_x = i;
                s_y = j;
            }
            else if (arr[i][j] == 3) {
                Q2.push(make_pair(i, j));
            }
        }
    }

    Ma();

    cout << bfs(s_x, s_y);

    
    return 0;
}
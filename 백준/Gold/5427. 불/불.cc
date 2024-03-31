#include<iostream>
#include<queue>
using namespace std;

int w, h, T;
queue<pair<int, int>> Q;
queue<pair<int, int>> Q2;
char arr[1002][1002];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void fire() {
    int cnt = Q2.size();
    for (int i = 0; i < cnt; i++) {
        int x = Q2.front().first;
        int y = Q2.front().second;
        Q2.pop();
        for (int j = 0; j < 4; j++) {
            int new_x = x + dx[j];
            int new_y = y + dy[j];

            if (new_y < 0 || new_x < 0 || new_x >= h || new_y >= w) continue;
            if (arr[new_x][new_y] != '.') continue;

            arr[new_x][new_y] = '*';
            Q2.push(make_pair(new_x, new_y));
        }
    }
}

int bfs() {
    int time = 0;

    while (!Q.empty()) {
        time++;
        fire();

        int cnt = Q.size();
        for (int t = 0; t < cnt; t++) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x < 0 || new_y < 0 || new_x >= h || new_y >= w) return time;

                if (arr[new_x][new_y] != '.')continue;

                arr[new_x][new_y] = '@';
                Q.push(make_pair(new_x, new_y));
            }
        }
    }
    return -1;
}

void Re(int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = '.';
        }
    }
    while (!Q.empty()) {
        Q.pop();
    }
    while (!Q2.empty()) {
        Q2.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--) {
        int x, y;

        cin >> w >> h;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    Q.push(make_pair(i, j));
                }
                else if (arr[i][j] == '*') {
                    Q2.push(make_pair(i, j));
                }
            }
        }

        int time = bfs();

        if (time == -1) cout << "IMPOSSIBLE" << "\n";
        else cout << time << "\n";

        Re(w, h);
    }


    return 0;
}
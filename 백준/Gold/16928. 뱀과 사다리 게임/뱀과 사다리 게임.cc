#include<iostream>
#include<queue>
#include<map>

using namespace std;

int N, M;
int visit[101];
int dice[6] = { 1,2,3,4,5,6 };
queue<int> Q;
map<int, int> L;
map<int, int> S;

int bfs(int start) {
    Q.push(start);
    visit[start] = 0;
    while (!Q.empty()) {
        int point = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++) {
            int np = point + dice[i];
            if (visit[np] != -1|| np > 100) continue;
            if (L.find(np) != L.end()) {
                visit[np] = 0;
                if (visit[L[np]] != -1)continue;
                visit[L[np]] = visit[point] + 1;
                Q.push(L[np]);
            }
            else if (S.find(np) != S.end()) {
                visit[np] = 0;
                if (visit[S[np]] != -1)continue;
                visit[S[np]] = visit[point] + 1;
                Q.push(S[np]);
            }
            else {
                visit[np] = visit[point] + 1;
                Q.push(np);
            }
            if (np == 100)return visit[np];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;

    cin >> N >> M;
    for (int i = 0; i < 101; i++) {
        visit[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        L[a] = b;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        S[a] = b;
    }

    cout << bfs(1);
    
    return 0;
}
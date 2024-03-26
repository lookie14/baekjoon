#include<iostream>
#include<queue>
using namespace std;

int N, K;
int H = 0, T = 0;
char arr[3001];
int dist[3001][3001];
queue<pair<int,int>> Q;

void bfs(int h, int t){
    Q.push(make_pair(h,t));
    dist[h][t] = 0;
    while(!Q.empty()){
        int hh = Q.front().first;
        int tt = Q.front().second;
        Q.pop();
        for(int i = 1; i<=K; i++){
            if(i<=hh&&(K-i)<=tt&&dist[hh-2*i+K][tt+2*i-K] == -1){
                dist[hh-2*i+K][tt+2*i-K] = dist[hh][tt] + 1;
                Q.push(make_pair(hh-2*i+K, tt+2*i-K));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
        if(arr[i] == 'H')H++;
        else T++;
    }
    for(int i = 0 ;i <= N; i++){
        for(int j = 0 ; j <= N; j++){
            dist[i][j] = -1;
        }
    }
    
    bfs(H,T);

    cout << dist[0][N];
    
    return 0;
}
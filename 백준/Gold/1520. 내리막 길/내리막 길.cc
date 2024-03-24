#include<iostream>

using namespace std;

int N, M;
int map[500][500];
int dp[500][500];
int dx[4] = { 1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x, int y){
    if( x== M -1 && y == N - 1){
        return 1;
    }
    int& ret = dp[x][y];
    if(ret!=-1)return ret;
    ret = 0;
    for(int i = 0 ; i < 4; i++){
        int new_x = dx[i] + x;
        int new_y = dy[i] + y;
        if(new_x<0||new_x >= M || new_y < 0 || new_y >= N) continue;
        if(map[new_x][new_y] >= map[x][y])continue;
        ret += dfs(new_x,new_y);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i = 0 ; i < M; i++){
        for(int j = 0 ; j < N; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0,0);
    
    return 0 ;
}
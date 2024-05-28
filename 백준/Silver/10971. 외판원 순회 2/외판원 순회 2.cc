#include<iostream>
#include<vector>
using namespace std;
int N, tmp;
vector<vector<int>>V(10);

int ans = 987654321;
bool visit[10];

void dfs(int num, int cost, int cur, int start){  //몇번째, 코스트 얼마, 현재도시, 출발
    if(num == N - 1){
        if(V[cur][start]!=0 && cost + V[cur][start]<ans){
            ans = cost + V[cur][start];
        }
        return ;
    }
    for(int i = 0 ; i < N; i++){
        if(!visit[i] && V[cur][i] != 0){  //방문을 안했고, cost가 0이 아니어야 함.
            visit[i] = true;
            dfs(num+1, cost + V[cur][i], i, start);
            visit[i] = false;
        }  
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i<N; i++){
        visit[i] = false;
    }
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N ;j++){
            cin >> tmp;
            V[i].push_back(tmp);
        }
    }

    for(int i = 0 ; i < N; i++){
        visit[i] = true;
        dfs(0,0,i, i);
        visit[i] = false;
    }
    cout << ans;
    return 0 ;
}
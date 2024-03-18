#include<iostream>
#include<stack>
using namespace std;

int N;
int arr[65][65];
bool visit[65][65] = {false, };
stack <pair<int,int>> S;
int dir_x[2] = {1,0};
int dir_y[2] = {0,1};

void dfs(int s_x, int s_y){
    visit[s_x][s_y] = true;
    S.push(make_pair(s_x, s_y));
    while(!S.empty()){
        int x = S.top().first;
        int y = S.top().second;
        S.pop();
        for(int i = 0 ; i < 2; i++){
            int new_x = x + dir_x[i]*arr[x][y];
            int new_y = y + dir_y[i]*arr[x][y];
            if(new_x < N && new_y < N && !visit[new_x][new_y]){
                visit[new_x][new_y] = true;
                S.push(make_pair(new_x, new_y));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0,0);

    if(visit[N-1][N-1] == true){
        cout << "HaruHaru";
    }else cout << "Hing";

    return 0;
}
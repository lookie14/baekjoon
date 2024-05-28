#include<iostream>

using namespace std;

int N;
int arr[15];
int p_x[30];  // N(15) 기준으로 -14 ~ 14 표현 1~29
int m_x[30];  // N(0) 기준으로 0 ~ 28 표현


int ans = 0;
int check(int idx, int y){
    return arr[y] || p_x[y - idx + N] || m_x[y + idx];
}
void dfs(int n){
    if(n == N){
        ans ++; return ;
    }
    for(int i = 0 ; i < N; i++){
        if(!check(n, i)){  //퀸 놓을 수 있는 자리인지 체크
            arr[i] = 1;
            p_x[i- n+N] = 1;
            m_x[i+n] = 1;
            dfs(n+1);
            arr[i] = 0;
            p_x[i-n+N] = 0;
            m_x[i+n] = 0;
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0 ;i < N; i++)arr[i] = 0;
    for(int i = 0 ; i < 30; i++){
        p_x[i] = 0;
        m_x[i] = 0;
    }

    dfs(0);

    cout << ans;

    return 0 ;
}
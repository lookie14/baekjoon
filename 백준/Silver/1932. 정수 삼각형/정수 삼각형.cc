#include<iostream>
#include<algorithm>

using namespace std;

int N;
int dp[500][500] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ;j <= i ; j++){
            cin >> dp[i][j];
        }
    }

    for(int i = 0 ;i < N; i++){
        for(int j = 0 ; j <= i; j++){
            if(j==0){
                dp[i][j] = dp[i-1][0] + dp[i][j];
            }else if(i == j){
                dp[i][j] = dp[i - 1][j-1] + dp[i][j];
            }else{
                dp[i][j] = max(dp[i-1][j-1] + dp[i][j], dp[i-1][j] + dp[i][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
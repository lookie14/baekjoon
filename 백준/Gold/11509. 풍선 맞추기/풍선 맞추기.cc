#include<iostream>

using namespace std;
int N, tmp;
int arr[1000001] = {0, };
int ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        if(arr[tmp] == 0){
            ans ++;
            arr[tmp-1]++;
        }else{
            arr[tmp-1]++;
            arr[tmp]--;
        }
    }
    cout << ans;
    return 0 ;
}
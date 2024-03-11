#include<iostream>
using namespace std;

int arr1[100001]; //주유소
int arr2[100001]; //도로
long long ans = 0;
int mini;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    for(int i = 0 ; i < N-1; i++){
        cin >> arr2[i];
    }
    for(int i = 0 ; i < N; i++){
        cin >> arr1[i];
        if(i ==0) mini = arr1[i];
    }

    ans += (long long)arr1[0]*arr2[0];
    for(int i = 1; i < N-1; i++){
        if(arr1[i] > mini){
            ans += (long long)mini*arr2[i];
        }else{
            ans += (long long)arr2[i]*arr1[i];
            mini = arr1[i];
        }
    }
    cout << ans;
    
    return 0;
}
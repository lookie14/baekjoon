#include<iostream>
#include<queue>
using namespace std;

int N;
int arr[10001];
int record[10001];
bool visit[10001];
int a, b;

void bfs(int start){
    queue<int> Q;
    Q.push(start);
    visit[start] = true;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(int i = 1; now + arr[now]*i <= N ; i++){
            if(visit[now + arr[now]*i] == false){
                record[now + arr[now]*i] = record[now] + 1;
                visit[now + arr[now]*i] = true;
                Q.push(now + arr[now]*i); 
            }
        }
        for(int i = -1; now + arr[now]*i >= 1 ; i--){
            if(visit[now + arr[now]*i] == false){
                record[now + arr[now]*i] = record[now] + 1;
                visit[now + arr[now]*i] = true;
                Q.push(now + arr[now]*i); 
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    cin >> a >> b;

    for(int i = 0; i<=N; i++){
        visit[i] = false;  //방문 초기화 -> 0일때만 새로 입력할거임
        record[i] = 0;
    }
    
    bfs(a);
    if(visit[b]){
        cout << record[b];
    }else {
        cout << -1;
    }

    return 0;
}
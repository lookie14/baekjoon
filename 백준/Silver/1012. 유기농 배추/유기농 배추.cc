#include<iostream>
#include<string.h>
using namespace std;
int arr[50][50] = {0};
int T, M, N, K;
int x, y; //배추좌표 
int cnt = 0;
void change_p(int xx, int yy){
	arr[xx][yy] = 0;
	if(xx<=48&&arr[xx+1][yy]==1)change_p(xx+1,yy);
	if(yy<=48&&arr[xx][yy+1]==1)change_p(xx,yy+1);
	if(yy>=1&&arr[xx][yy-1]==1)change_p(xx,yy-1);
	if(xx>=1&&arr[xx-1][yy]==1)change_p(xx-1,yy);
}
void change(int xx, int yy){
	if(arr[xx][yy]==1){
		arr[xx][yy] = 0;
		cnt ++;
		if(xx<=48&&arr[xx+1][yy]==1)change_p(xx+1,yy);
		if(yy<=48&&arr[xx][yy+1]==1)change_p(xx,yy+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> M >> N >> K;
		for(int i = 0; i < K ;i ++){
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for(int i = 0 ; i < M; i++){
			for(int j = 0 ; j< N; j++){
				change(i,j);
			}
		}
		cout << cnt << "\n";
		for(int i = 0 ; i < 50; i++){
			memset(arr[i], 0, sizeof(int)*50);
		}
		cnt = 0;
	}
	return 0;
}
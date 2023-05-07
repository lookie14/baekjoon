#include<iostream>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long arr[100] = {1,1,1,2,2,3,4,5,7,9,};
	for(int i = 10; i < 100 ; i++){
		arr[i] = arr[i-5] + arr[i-1];
	}
	int T, N;
	cin >> T;
	
	while(T--){
		cin >> N;
		cout << arr[N-1] << "\n";
	}
	return 0;
}
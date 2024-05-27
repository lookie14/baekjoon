#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr0[41];
	int arr1[41];
	arr0[0] = 1, arr0[1] = 0;
	arr1[0] = 0, arr1[1] = 1;
	for(int i = 2;i<=40; i++){
		arr0[i] = arr0[i-1]+arr0[i-2];
		arr1[i] = arr1[i-1]+arr1[i-2];
	}
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		cout << arr0[N] << " " << arr1[N] << "\n";
	}
	return 0;
}
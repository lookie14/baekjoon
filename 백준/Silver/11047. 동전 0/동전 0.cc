#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N, K;
	int money;
	vector <int> v;
	cin >> N >> K;
	for(int i = 0 ; i < N ; i++){
		cin >> money;
		v.push_back(money);
	}
	int sp;
	int count = 0;
	for(int i = N-1; i >= 0 ; i--){
		if(K>=v[i]){
			sp = i;
			break;
		}
	}
	for(int i = sp ; i >=0 ; i--){
		count += K/v[i];
		K = K%v[i];
		if(K == 0)break;
	}
	cout << count;
	return 0;
}

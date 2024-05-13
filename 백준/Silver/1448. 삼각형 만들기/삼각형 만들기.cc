#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int sum = -1;
vector<int> V;

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
    cin >> N;
    for(int i = 0 ; i < N; i++){
        int tmp; cin >> tmp;
        V.push_back(tmp);
    }
    sort(V.rbegin(),V.rend());
    for(int i = 0; i<N-2; i++){
		if(V[i]<V[i+1]+V[i+2]){
					sum = V[i]+V[i+1]+V[i+2];
					break;
		}
	}
    cout << sum;
    return 0;
}
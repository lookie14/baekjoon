#include<iostream>
#include<string>
using namespace std;

int N, M;
int ans = 0;
char S[1000001];
char CS[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> S[i];
	}

	for (int i = 0; i < 2*N+1; i++) {
		if (i % 2 == 0)CS[i] = 'I';
		else CS[i] = 'O';
	}
	
	for (int i = 0; i < M - 2 * N ; i++) {
		int flag = 1;
		for (int j = 0; j < 2 * N + 1; j++) {
			if (S[i + j] != CS[j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) ans++;
	}
	cout << ans;
	return 0;
}
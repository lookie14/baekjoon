#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string MBTI[100001];
int T, N;

int tri_dis(string a, string b, string c) {
	int rst = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) rst++;
		if (c[i] != b[i]) rst++;
		if (a[i] != c[i]) rst++;
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int mini = 12;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> MBTI[i];
		if (N > 32) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0; i < N - 2; i++) {
			for (int j = i + 1; j < N - 1; j++) {
				for (int k = j + 1; k < N; k++) {
					mini = min(mini, tri_dis(MBTI[i], MBTI[j], MBTI[k]));
				}
			}
		}
		cout << mini << "\n";
	}
	return 0;
}
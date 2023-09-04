#include<iostream>

using namespace std;
//가로 길이가 5아래이면 이동방법에 제약이 없음 -> 높이에 의해 4가지 이동방법을 못쓸 경우도 발생할 수 있다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int rst = 0;
	int N, M;
	cin >> N >> M;
	if (N == 1) {
		rst = 1;
	}
	else if (N == 2) {
		if (M <= 7) rst = (M + 1) / 2;
		else rst = 4;
	}
	else {
		if (M < 7) {
			if (M >= 5) rst = 4;
			else rst = M;
		}
		else {
			rst = 5 + (M - 7);
		}
	}
	cout << rst;
	return 0;
}

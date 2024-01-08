#include<iostream>
#include<queue>

using namespace std;

int arr[1001][1001];
bool check[1001][1001];
int ans[1001][1001];
int n, m;

struct pt {
	int x, y;
};

pt start;
queue <pt> Q;

void dfs(pt a) {
	Q.push(a);
	while (!Q.empty()) {
		int X = Q.front().x;
		int Y = Q.front().y;
		Q.pop();
		if (Y - 1 > 0 && check[Y - 1][X] != true) {  //상
			ans[Y - 1][X] = ans[Y][X] + 1;
			check[Y - 1][X] = true;
			pt np = { X ,Y - 1 };
			Q.push(np);
		}
		if (Y + 1 <= n && check[Y + 1][X] != true) {  //하
			ans[Y + 1][X] = ans[Y][X] + 1;
			check[Y + 1][X] = true;
			pt np = { X ,Y + 1 };
			Q.push(np);
		}
		if (X - 1 > 0 && check[Y][X - 1] != true) {  //좌
			ans[Y][X - 1] = ans[Y][X] + 1;
			check[Y][X - 1] = true;
			pt np = { X - 1,Y };
			Q.push(np);
		}
		if (X + 1 <= m && check[Y][X + 1] != true) {  //우
			ans[Y][X + 1] = ans[Y][X] + 1;
			check[Y][X + 1] = true;
			pt np = { X + 1,Y};
			Q.push(np);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				check[i][j] = true;
				ans[i][j] = 0;
			}
			if (arr[i][j] == 2) {
				start.x = j;
				start.y = i;
			}
		}
	}

	ans[start.y][start.x] = 0;
	check[start.y][start.x] = true;
	dfs(start);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] != true) ans[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

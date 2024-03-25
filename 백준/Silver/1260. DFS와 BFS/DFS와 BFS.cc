#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int arr[1001][1001];
int visited[1001];
int N, M, V;

void DFS(int V) {
	visited[V] = 1;
	cout << V << " ";
	for (int i = 1; i <= N; i++) {
		if (arr[V][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
		if (i == N)return;
	}
}
void BFS(int V) {
	queue<int> q;
	q.push(V);
	while (!q.empty()) {
		int next = q.front();
		visited[next] = 1;
		cout << next << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[next][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		 }
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	DFS(V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	BFS(V);
	return 0;
}
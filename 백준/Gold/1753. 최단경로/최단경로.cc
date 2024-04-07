#include<iostream>
#include<queue>
#include<vector>

#define INF 987654321

using namespace std;

int V, E, N;
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

int dist[20001];
vector<pair<int,int>> arr[20001];

void dijkstra(int start){
    dist[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int current = pq.top().second;
        int stcd = pq.top().first;
        pq.pop();
        if(dist[current] < stcd)continue;

        for(int i = 0 ; i < arr[current].size();++i){
            int next = arr[current][i].second;
            int stnd = stcd + arr[current][i].first;
            if(dist[next] > stnd){
                dist[next] = stnd;
                pq.push(make_pair(stnd, next));
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E ;
    cin >> N;

    for(int i = 1; i < V+1; i++){
        dist[i] = INF;
    }

    for(int i = 0 ; i < E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(c,b));
    }

    dijkstra(N);

    for(int i = 1; i < V+1; i++){
        if(dist[i] == INF){
            cout << "INF" << "\n";
        } 
        else {
            cout << dist[i] << "\n";
        }
    }
    

    return 0;
}
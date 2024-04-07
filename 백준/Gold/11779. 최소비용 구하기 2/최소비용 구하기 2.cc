#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321;

using namespace std;

int N, M, Start, End;
int dist[1001];
int route[1001];
vector<pair<int,int>> V[1001];
vector<int> route_v;
priority_queue<pair<int,int>> pq;

void dijkstra(int start){
    pq.push(make_pair(0,start));
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost > dist[cur])continue;
        for(int i = 0 ; i < V[cur].size(); i++){
            int next = V[cur][i].first;
            int ncost = V[cur][i].second;

            if(dist[next] > cost + ncost){
                route[next] = cur;
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next],next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N ; i++)dist[i] = INF;
    for(int i = 0 ; i < M ; i++){
        int a,b,c;
        cin >> a>> b>>c;
        V[a].push_back(make_pair(b,c));
    }
    cin >> Start >> End;

    dijkstra(Start);

    cout << dist[End] << "\n";
    int Temp = End;
    while(Temp){
        route_v.push_back(Temp);
        Temp = route[Temp];
    }
    cout << route_v.size() << "\n";
    for(int i = route_v.size() - 1 ; i >=0 ; i--) cout << route_v[i] << " ";
    cout << "\n";

    return 0;
}
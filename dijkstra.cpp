#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;

#define ll long long
#define N 1000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();




bool visited[N];
vector<pii> adj[N];
vector<int>dist(N, INT_MAX);
void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(auto vpii:adj[u]){
            int v = vpii.first;
            int w = vpii.second;

            if(visited[v])continue;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin>>n>>m;
    for(int i = 1; i<=m;i++){
        int u,v, w;
        cin>>u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);
    for(int i = 1;i<=n;i++){
        cout<< "dist "<<i<<" : "<<dist[i] << endl;
    }
    //cout<<endl;
    cout<<dist[7];
    return 0;
}
/*
7
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;

#define ll long long
#define N 1008
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();




bool visited[N];
vector<pii> graph[N];
vector<int>dist(N, INT_MAX);
void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>>q;
    dist[s]=0;
    q.push({dist[0], s});

    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        visited[u] = true;
        for(auto vpii:graph[u]){
            int v = vpii.first;
            int w = vpii.second;

            if(visited[v])continue;
            if(dist[v]>w+dist[u]){
                dist[v]=w+dist[u];
                q.push({dist[v], v});
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
        graph[u].push_back({v, w});
        //graph[v].push_back({u, w});
    }
    int s, t;
    cin >> s;
    dijkstra(s);
    cin>>t;
    for(int i = 1;i<=t;i++){
        int d, rd;
        cin >> d >> rd;
        if(dist[d]<=rd)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    cout<<endl;
    // cout<<dist[7];
    return 0;
}
/*
5 7
1 2 10
1 3 2
3 2 1
2 4 7
3 4 2
4 5 5
2 5 2
1
5
1 0
2 5
3 1
4 4
5 6
*/
#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define N 1000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();


typedef pair<int, int>pii;
int n , m;
vector<int>dist(N, INT_MAX);
bool visited[N];
vector<pii> graph[N];
vector<pair<pii,int>>list_of_edge;

void bellMan(int s){
    dist[s] = 0;
    for(int i = 1; i<n; i++){
        for(auto e:list_of_edge){
            int u = e.first.first;
            int v = e.first.second;
            int w = e.second;
            if(dist[u] != N && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 1; i<=m;i++){
        int u,v, w;
        cin>>u >> v >> w;
        graph[u].push_back({v, w});
        list_of_edge.push_back({{u, v},w});
        //graph[v].push_back({u, w});
    }
    bellMan(1);
    // vector<int>dist(N, INT_MAX);
    // dist[1] = 0;
    // for(int i = 1; i<n; i++){
    //     for(int u = 1; u<=n;u++){
    //         for(auto vpii:graph[u]){
    //             int v = vpii.first;
    //             int w = vpii.second;
    //             if(dist[u] != N && dist[v] > dist[u] + w){
    //                 dist[v] = dist[u] + w;
    //             }
    //         }
    //     }
    // }
    for(int i = 1;i<=n;i++){
        cout<< "dist "<<i<<" : "<<dist[i] << endl;
    }
    //cout<<endl;
    cout<<dist[7];
    return 0;
}
/*
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
4 7 3
*/
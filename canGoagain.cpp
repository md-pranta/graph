#include <bits/stdc++.h>
using namespace std;

#define ll long long
const long long INF = numeric_limits<long long>::max();
const int N = 1005;
typedef pair<int, int>pii;


int n , m;
vector<ll>dist(N, INF);
vector<pair<pii,ll>>list_of_edge;
int c = 0;
void bellMan(int s){
    dist[s] = 0;
    for(int i = 1; i<n; i++){
        for(auto e:list_of_edge){
            int u = e.first.first;
            int v = e.first.second;
            ll w = e.second;
            if(dist[u] != INF && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }

    }
    for(auto e:list_of_edge){
        int u = e.first.first;
        int v = e.first.second;
        ll w = e.second;
        if(dist[u] != INF && dist[v] > dist[u] + w){
               c = 1;
               break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 1; i<=m;i++){
        int u,v;
        ll w;
        cin>>u >> v >> w;
        list_of_edge.push_back({{u, v},w});
        //graph[v].push_back({u, w});
    }
    int s, t;
    cin >> s >> t;
    bellMan(s);
    if(c)cout<<"Negative Cycle Detected"<<endl;
    while(t--){
        int d;
        cin >> d;
        if(c)continue;
        else{
            if(dist[d]!=INF)cout<<dist[d] << endl;
            else cout<<"Not Possible"<<endl;
        }
    }
    return 0;
}
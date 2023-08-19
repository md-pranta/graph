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





void dfs(vector<int>adj[],bool visited[10000],int u){
    //
    visited[u] = true;
    cout << u << endl;
    for(int v:adj[u]){
        //
        if(visited[v])continue;
        dfs(adj, visited,v);
        //
    }
    //
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    bool v[n];
    vector<int> adj[100000];
    for(int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visited[100000];
    
    dfs(adj, visited,1);

    return 0;
}

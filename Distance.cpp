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

int bfs(vector<vector<int>>adj, vector<bool>visited, vector<int>distance, int s, int d){

    queue<int>q;
    q.push(s);
    visited[s] = true;
    distance[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                distance[v] = distance[u]+1;
            }
        }
    }
    return distance[d];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(1e5);
    vector<bool> visited(1e5, false);
    vector<int>distance(1e5,-1);
    for(int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    for(int i = 0; i <q; i++){
        int s, d;
        cin >> s >> d;
        cout << bfs(adj, visited, distance, s, d) << endl;
    }
    

    return 0;
}

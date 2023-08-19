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

void bfs(vector<vector<int>>adj, vector<bool>visited,vector<bool>done ,int l){
    set<int>ans;
    queue<int> q;
    q.push(l);
    visited[l] = true;
    int cnt  = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(done[u])continue;
        done[u] = true;
        for(int v:adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                cnt ++;
            }
        }
    }
    cout << cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(200+7);
    vector<bool> visited(200, false);
    vector<bool>done(200,false);
    for(int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int l;
    cin>>l;
    bfs(adj, visited,done,l);
    return 0;
}

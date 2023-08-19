#include<bits/stdc++.h>
using namespace std;

#define ll long long
//#define N 1000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();

int N = 100001;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);
set<int>ans;
void bfs(int l){
    queue<pair<int, int>>q;
    q.push({0, 0});
    visited[0] = true;
    while(!q.empty()){
        int u = q.front().first;
        int level = q.front().second;
        q.pop();
        if(level == l){
            ans.insert(u);
        }
        for(int v:adj[u]){
            if(visited[v])continue;
            q.push({v,level+1});
            visited[v] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l;
    cin>>l;
    bfs(l);
    if(ans.empty()) cout <<-1;
    else for(int a:ans)cout<< a <<" ";

    return 0;
}

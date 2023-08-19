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

int N = 1001;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);
vector<int>ans;
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s] = true;
    int cnt = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        cnt++;
        for(int v:adj[u]){
            if(visited[v])continue;
            q.push(v);
            visited[v] = true;
        }
    }
    if(cnt > 1) ans.push_back(cnt);
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
    for(int i = 0; i < N; i++){
        if(!visited[i]) bfs(i);
    }
    sort(ans.begin(), ans.end());
    for(int a:ans) cout << a << " ";

    return 0;
}

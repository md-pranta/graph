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




bool visited[N];
vector<int> adj[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        //
        for(int v:adj[u]){
            //
            if(visited[v])continue;
            q.push(v);
            visited[v] = true;
            //

        }
        //
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    bool v[n];
    for(int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs(1);

    return 0;
}

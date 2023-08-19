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
int level[N];
int parent[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(visited[v])continue;
            visited[v]=true;
            level[v] = level[u]+1;
            q.push(v);
            parent[v] = u;
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
    }
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout<<level[d]<<endl;

    for(int i = 1; i<=n; i++){
        cout<<i<<":"<<parent[i]<<" ";
    }
    cout<<endl;
    vector<int>path;
    int current = d;
    while(current != -1){
        path.push_back(current);
        current = parent[current];
    }
    for(int v:path){
        cout<<v<< " ";
    }
    cout<<endl;


    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 10000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();




bool visited[N];
vector<int> graph[N];
int level[N];
int parent[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:graph[u]){
            if(visited[v])continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] +1;
            parent[v] = u;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int first=1, second=1;
    for(int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        if(u ==  1 || v == 1)first = 0;
        if(u == n || v == n)second = 0;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    if(level[n]!=0){
        int current = n;
        vector<int>path;
        while(current!=-1){
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for(int v:path)cout<<v<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}

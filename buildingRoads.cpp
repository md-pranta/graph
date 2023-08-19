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


vector<int>graph[N];
bool visited[N];
void dfs(int u){
    visited[u] = true;
    for(auto v : graph[u]){
        if(visited[v])continue;
        dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>head;
    for(int i =1; i <= n; i ++){
        if(visited[i])continue;
        head.push_back(i);
        dfs(i);
    }
    int len = head.size();
    cout<<len-1<<endl;
    for(int i = 1; i < len; i++)
    cout<<head[i-1]<<" "<<head[i]<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    //map<int,set<int>>g;
    vector<long>adj[100005];
    bool visited[N];
    
    int e;
    cin>>e;
    for(int i = 0; i < e;i++){
        long u, v;
        cin >> u >> v;
        visited[v]=true;
        if(visited[u])adj[v].push_back(u);
        else adj[u].push_back(v);
        // if(visited[u])g[v].insert(u);
        // else g[u].insert(v);
    }
    // for(auto m=g.begin(); m != g.end(); m++){
    //     int x = m->first;

    //     set<int> st = m->second;
    //     for(auto it=st.begin(); it!=st.end();it++){
    //         cout<<x<<" "<<*it<<endl;
    //     }
    // }
    for(int i = 0; i <= 100005; i++){
        sort(adj[i].begin(), adj[i].end());
        for(auto v:adj[i])cout<<i<<" "<<v<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 1000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();
typedef pair<int, int>pii;


bool comparegraph(pii u,pii v) {
    if(u.first == v.first) return u.second < v.second;
    return u.first < v.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int e;
    cin >> e;

    vector<pii> graph;
    //map<int,set<int>>g;
    //bool visited[N];
    

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph.push_back({u, v});
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
    sort(graph.begin(), graph.end(), comparegraph);
    for (auto p : graph) {
        cout << p.first << " " << p.second <<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
typedef pair<ll, int>pii;

const ll INF = numeric_limits<ll>::max();
const int N = 100006;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, long long>>> graph(n + 1);
    for (int i = 0; i < e; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;

        vector<long long> distance(n + 1, INF);
        priority_queue<pii, vector<pii>, greater<>> pq;

        distance[x] = 0;
        pq.push({0, x});

        while (!pq.empty()) {
            int u = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();

            if (dist > distance[u]) continue;

            for (auto vpii : graph[u]) {
                int v = vpii.first;
                ll w = vpii.second;
                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    pq.push({distance[v], v});
                }
            }
        }

        if (distance[y] == INF) {
            cout << -1 << endl;
        } else {
            cout << distance[y] << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = numeric_limits<ll>::max();
const int N = 100006;
int main()
{
    int n, e;
    cin >> n >> e;
    ll dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    int q;
    cin >>q;
    for (int j = 1; j <= q; j++){
        int src, des;
        cin >> src >> des;
        if (dis[src][des] == INF)cout <<"-1"<<endl;
        else cout << dis[src][des] <<endl;
    }
    return 0;
}
/*
5
7
1 2 2
1 3 6
2 3 1
3 4 4
4 2 6
2 5 3
5 4 9
*/
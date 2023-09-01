#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = numeric_limits<ll>::max();
const int N = 100006;

int main(){
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
        if(dis[a][b] <= w)continue;
        dis[a][b] = w;
    }
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         if (dis[i][j] == INF)
    //             cout << "INF"
    //                  << " ";
    //         else
    //             cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++){
                if (dis[i][k] != INF && dis[k][j] != INF) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if (dis[x][y] == INF)
            cout <<-1<<endl;
        else
            cout << dis[x][y] <<endl;
    }
    return 0;
}
/*
4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2
*/
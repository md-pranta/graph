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


typedef pair<int, int>pii;

int d[N][N]={N};

void bellMan(int s){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
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
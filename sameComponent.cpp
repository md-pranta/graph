#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;

#define ll long long
#define N 1000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();


int n, m;
vector<string> g;
bool visited[1005][1005], flag = true;
bool isValid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int sr, int sc){
    if(!isValid(sr, sc) or g[sr][sc]!='.')return;

    g[sr][sc]='A';
    dfs(sr, sc-1);
    dfs(sr, sc+1);
    dfs(sr-1, sc);
    dfs(sr+1, sc);
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        g.push_back(s);
    }
    int sr, sc, dr, dc;
    cin >>sr>>sc;
    cin >>dr>>dc;
    dfs(sr, sc);
    if(isValid(dr, dc) and g[dr][dc]=='A')cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}
/*
5 4
..-.
---.
..-.
--..
....
0 1
3 2
*/
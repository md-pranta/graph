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


int n, m, x,area=INT_MAX;
vector<string> g;
bool visited[1005][1005], flag = true;
bool isValid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int sr, int sc){
    if(!isValid(sr, sc) or g[sr][sc]!='.')return;
    x++;
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j]=='.'){
                dfs(i, j);
                area = min(area, x);
                x = 0;
            }
        }
    }
    if(area==INT_MAX)cout<<"-1"<<endl;
    else cout<<area<<endl;


    return 0;
}
/*
6 5
..-..
..-..
-----
.-...
.----
.....
*/
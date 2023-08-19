#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();


vector<string>graph;
bool visited[N][N];
int n , m;
bool isValid(int i, int j){
    return (i >= 0 and i < n) and (j >= 0 and j < m);
}
void dfs(int i,int j){
    if(!isValid(i , j))return;
    if(graph[i][j]=='#')return;
    if(visited[i][j]) return;

    visited[i][j] = true;

    dfs(i,j+1);
    dfs(i, j-1);
    dfs(i-1, j);
    dfs(i+1, j);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i<n; i++){
        string s;
        cin >> s;
        graph.push_back(s);
    }
    int room = 0;
    for(int i = 0; i < n; i++){
        for(int j= 0; j< m; j++){
            if(graph[i][j]=='#')continue;
            if(visited[i][j]) continue;
            dfs(i , j);
            room +=1;
        }
    }
    cout << room;
    return 0;
}

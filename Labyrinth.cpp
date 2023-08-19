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
typedef pair<int, int>pii;

vector<string>graph;
bool visited[N][N];
int n , m;
int level[N][N];
pii parent[N][N];
bool isValid(int i, int j){
    return (i >= 0 and i < n) and (j >= 0 and j < m);
}
void bfs(int si,int sj){
    queue<pair<int, int>>q;
    q.push({si, sj});
    level[si][sj] = 0;
    visited[si][sj] =true;
    parent[si][sj] = {-1, -1};

    while(!q.empty()){

        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(auto v:vector<pair<int, int>>{{0,1}, {0,-1}, {-1,0}, {1,0},}){

            int vi = v.first + i;
            int vj = v.second + j;

            if(isValid(vi , vj) and (graph[vi][vj]!='#') and (!visited[vi][vj])){
                q.push({vi, vj});
                visited[vi][vj] = true;
                parent[vi][vj] = {i, j};
                level[vi][vj] = level[i][j] + 1;
            }
        }
    }
}
void direction(int i,int j){
    vector<pii>path;
    pii current = {i, j};
    while (current.first!=-1 and current.second != -1){
        path.push_back(current);
        current = parent[current.first][current.second];
    }
    reverse(path.begin(), path.end());
    for(int i = 1; i<path.size();i++){
        if(path[i].first == path[i-1].first){
            if(path[i].second+1 == path[i-1].second){
                cout<<"L";
            }
            else cout<<"R";
        }
        else{
            if(path[i].first-1 == path[i-1].first){
                cout<<"D";
            }
            else cout<<"U";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int si, sj, ei,ej;
    for(int i = 0;i<n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j]=='A'){
                si = i;
                sj=j;
            }
            if(s[j]=='B'){
                ei = i;
                ej=j;
            }
        }
        graph.push_back(s);
    }
    bfs(si, sj);
    
    if(level[ei][ej] != 0){
        cout<<"YES\n" << level[ei][ej] <<endl;
        direction(ei, ej);
    }
    else cout<<"NO\n";
    
    return 0;
}

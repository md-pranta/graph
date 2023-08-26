#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 106
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();
typedef pair<int, int>pii;

int visited[N][N];
int level[N][N];
int n,m;
vector<pii> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(int si, int sj){
	queue<pii> q;
	q.push({si,sj});
	visited[si][sj] = true;
	level[si][sj] = 0;

	while(!q.empty()){
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for(auto v:dir){
			int vi = i+v.first;
			int vj = j+v.second;

			if(!isValid(vi,vj) or visited[vi][vj]) continue;
			q.push({vi,vj});
			visited[vi][vj] = true;
			level[vi][vj] = level[i][j]+1;
		}
	}
}

void clear(){
	for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		level[i][j] = 0;
    		visited[i][j] = false;
    	}
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin >> n >> m;
        int sc, sr, dr, dc;
        cin >> sr >> sc;
        cin >> dr >> dc;
        bfs(sr, sc);
        if(visited[dr][dc])cout<<level[dr][dc]<<endl;
        else cout<<-1<<endl;
        clear();
    }
    return 0;
}


/*
4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
*/
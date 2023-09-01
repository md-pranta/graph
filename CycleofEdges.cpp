#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();
typedef pair<int, int>pii;


int parent[N];
int Size[N];
void make_sets(int n){
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        Size[i] = 1; 
    }
}
int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void union_sets(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b]; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll e;
    cin >> n >> e;
    make_sets(n);
    int cnt = 0;
    while(e--){
        int u, v;
        cin >> u >> v;
        if(find(u)==find(v)) cnt++;
        union_sets(u, v);
    }
    cout<<cnt<<endl;
    return 0;
}
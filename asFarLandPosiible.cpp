#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool visited[101][101];
    bool isValid(int i, int j, int n){
        if((i < 0 || i >= n) || (j < 0 || j >= n)) return false;
        if(visited[i][j])return false;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int , int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j])q.push({i, j});
            }
        }
        int dis = 0;
        if(q.size()==n*n or q.size()==0)return -1;
        
        vector<pair<int, int>>dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int sr = q.front().first;
                int sc = q.front().second;
                q.pop();
                for(auto v:dir){
                    int vi = sr + v.first;
                    int vj = sc + v.second;
                    if(isValid(vi, vj, n)){
                        visited[vi][vj] = true;
                        q.push({vi, vj});
                    }
                }
            }
            dis++;
        }
        return dis-1;
    }
};
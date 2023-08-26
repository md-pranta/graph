#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n, m;
    bool visited[501][501], flag = true;
    bool isValid(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int sr, int sc){
        if(!isValid(sr, sc) or !grid2[sr][sc])return;

        if(grid1[sr][sc]==0)flag = false;
        grid2[sr][sc]=0;
        dfs(grid1,grid2,sr, sc-1);
        dfs(grid1,grid2,sr, sc+1);
        dfs(grid1,grid2,sr-1, sc);
        dfs(grid1,grid2,sr+1, sc);
        
    }
    int cnt = 0;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid2[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j]){
                    dfs(grid1, grid2,i, j);
                    if(flag)cnt++;
                    else flag = true;
                }
            }
        }
        return cnt;
    }
};
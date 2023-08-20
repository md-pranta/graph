class Solution {
public:
    bool visited[500][500];
    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && i < m ) and (j >= 0 && j < n);
    }
    void dfs(vector<vector<char>>& grid,int i, int j,int n, int m){
        if(!isValid(i, j , n, m) or grid[i][j]=='0' or visited[i][j])return;
        visited[i][j] = true;
        dfs(grid,i, j-1,n,m);
        dfs(grid,i, j+1,n,m);
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int island = 0;
        for(int a = 0; a< m; a++){
            for(int b = 0; b < n; b++){
                if(visited[a][b])continue;
                if(grid[a][b]=='0') continue;
                island++;
                dfs(grid,a, b,n, m);
            }
        }
    return island;
    }
};
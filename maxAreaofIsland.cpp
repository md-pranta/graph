class Solution {
public:
    int n , m;
    vector<vector<int>>*g;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = &grid;
        int val = 0;
        for(int a = 0; a< n; a++){
            for(int b = 0; b < m; b++){
                if(grid[a][b]==0)continue;
                if(grid[a][b]==0) continue;
                auto area = dfs(a, b);
                val = max(area, val);
            }
        }
        return val;
    }
    int dfs(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0 ;

        if((*g)[i][j] != 1) return 0;

        (*g)[i][j] = 0;

        int bottom = dfs(i+1, j);
        int top = dfs(i-1, j);
        int right = dfs(i, j+1);
        int left = dfs(i, j-1);
        return bottom + top + left + right + 1;
    }
};
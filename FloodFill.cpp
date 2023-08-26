#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000006
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define M 10000000007
#define all(x) x.begin(), x.end()
#define kill(x) return cout << x << endl, void();

class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return (i >= 0 && i < n ) and (j >= 0 && j < m);
    }
    void dfs(vector<vector<int>>& grid,int i, int j,int n, int m,int color, int newColor){
        if(!isValid(i, j , n, m) or grid[i][j]!=color)return;
        grid[i][j] = newColor;
        dfs(grid,i, j-1,n,m,color,newColor);
        dfs(grid,i, j+1,n,m,color,newColor);
        dfs(grid,i+1,j,n,m,color,newColor);
        dfs(grid,i-1,j,n,m,color,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc]==color){return image;}
        dfs(image,sr, sc,n, m,image[sr][sc],color);
        return image;
    }
};
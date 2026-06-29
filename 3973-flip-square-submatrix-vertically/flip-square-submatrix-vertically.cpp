class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size(), m=grid[0].size();
        int xx = x+k, yy = y+k;


        for(int i =x;i<x+k/2;i++){
            for(int j =y;j<yy; j++){
                swap(grid[i][j],grid[x+k-1 - (i-x)][j]);
            }
        }
        return grid;
    }
};
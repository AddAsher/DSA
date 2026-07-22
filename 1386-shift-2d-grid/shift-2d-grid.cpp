class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int N = m * n;
        k %= N;

        vector<vector<int>> result(m, vector<int>(n));

        for (int idx = 0; idx < N; idx++) {
            int srcIdx = (idx - k + N) % N;  // where this value comes from
            int srcRow = srcIdx / n;
            int srcCol = srcIdx % n;

            int destRow = idx / n;
            int destCol = idx % n;

            result[destRow][destCol] = grid[srcRow][srcCol];
        }

        return result;

    }
};
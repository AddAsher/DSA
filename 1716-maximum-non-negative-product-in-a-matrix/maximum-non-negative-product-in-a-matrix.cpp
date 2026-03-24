class Solution {
public:
    typedef long long ll;
    int modulo = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>>dp_max(n, vector<ll>(m,0));
        vector<vector<ll>>dp_min(n, vector<ll>(m,0));
        dp_max[0][0] = dp_min[0][0] = grid[0][0];

        for(int i=1;i<n;i++){
            dp_max[i][0] = dp_min[i][0] = dp_max[i-1][0]*grid[i][0];
        }
        for(int j=1;j<m;j++){
            dp_max[0][j] = dp_min[0][j] = dp_max[0][j-1]*grid[0][j];
        }

        for(int i = 1;i<n;i++) {
            for(int j =1 ;j<m;j++){
                ll a = dp_min[i-1][j] * grid[i][j];
                ll b = dp_max[i-1][j] * grid[i][j];
                ll c = dp_min[i][j-1] * grid[i][j];
                ll d = dp_max[i][j-1] * grid[i][j];
                dp_min[i][j] = min({a,b,c,d});
                dp_max[i][j] = max({a,b,c,d});
            }
        }
        if(dp_max[n-1][m-1]<0) return -1;
        return dp_max[n-1][m-1] % modulo;        
    }
};
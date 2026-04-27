class Solution {
public: 
    vector<int> parent;

    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n =grid[0].size();
        parent.resize(m*n);
        iota(parent.begin(), parent.end(),0);

        for (int i =0; i < m; i++){
            for (int j=0; j<n; j++){
                int curr = i*n + j;

                //check right neighbor
                if(j+1 < n){
                    int right = i * n +j+1;
                    bool currHasRight = grid[i][j]==1 || grid[i][j]==4 || grid[i][j]==6;
                    bool rightHasLeft = grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5;
                    if ( currHasRight && rightHasLeft) {
                        unite(curr, right);
                    } 
                }

                //check down neighbor
                if(i+1 < m){
                    int down = (i+1)*n + j;
                    bool currHasDown = grid[i][j] == 2 || grid[i][j] == 3 || grid[i][j] == 4;
                    bool downHasUp = grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6;
                    if(currHasDown && downHasUp){
                        unite(curr, down);
                    }                    
                }

            }
        }

        return find(0) == find((m-1) * n + (n-1));
    }

    // bool canConnect(int curr, int next){ //tests if two roads can connect
    //     if(curr ==1){
    //         return next%2==1;
    //     }
    //     if (curr==2){
    //         return next%2==0;
    //     }
    //     if (curr==3)
    // }
};
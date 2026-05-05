class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // add - 1 to all n-j or n-i
        for(int i=0; i<n/2; i++){
            for(int j = 0+i; j<n-i-1;j++){
                int temp = matrix[i][j];
                matrix[i][j] =  matrix[n-j-1][i];
                matrix[n-j-1][i]= matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] =temp;
            }
        }
        
    }
};
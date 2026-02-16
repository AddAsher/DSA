class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = n-1;

        while(start<=end) {
            int mid = start + (end-start)/2;
            
            if(target == matrix[row][mid]){
                return true;
            } else if(target > matrix[row][mid]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;        
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m-1;

        while(left<=right) {
            int mid = left + (right-left)/2;
            if(matrix[mid][0]>target){
                right = mid-1;
            } else if(matrix[mid][n-1]<target){
                left = mid+1;
            } else {
                return searchInRow(matrix, target, mid);
            }
        }
        return false;
    }
};
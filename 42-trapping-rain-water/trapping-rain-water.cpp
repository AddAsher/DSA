class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftmax(height.size(), 0);
        vector<int> rightmax(height.size(), 0);
        int res = 0;

        leftmax[0] = height[0];
        for(int i =1; i<height.size(); i++){
            leftmax[i] = max(height[i], leftmax[i-1]);
        }

        rightmax[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2;i>=0;i--){
            rightmax[i] = max(height[i], rightmax[i+1]);
        }

        for(int i = 0; i<height.size(); i++){
            res += min(rightmax[i], leftmax[i]) - height[i];
        }

        return res;
        
    }
};
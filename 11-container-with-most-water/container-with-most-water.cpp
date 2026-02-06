class Solution {
public:
    int maxArea(vector<int>& height) {
            int maxArea = 0;
            int left = 0;
            int right = height.size()-1;
            while(left<right){
                int xdistance = right - left;
                int ydistance = min(height[left], height[right]);
                int area = xdistance * ydistance;
                maxArea = max(area,maxArea);
                if (height[left]>height[right]){
                    right--;
                } else{
                    left++;
                }
            }
            return maxArea;
    }
};
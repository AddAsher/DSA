class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;

        for (int l = 0;l<n; l++){
            int targetCount = 0;

            for (int r = l;r<n;r++){
                if(nums[r]==target){
                    targetCount++;
                }
                if(targetCount> ((r-l+1)/2)){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
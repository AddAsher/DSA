class Solution {
public:
    bool check(vector<int>& nums) {
        int start= nums[0];
        int n = nums.size();
        int end = nums[n-1];
        int prev = start;
        int restart=0;
        if (end>start) restart++;
        for(int i=0;i<nums.size();i++){
            if(prev>nums[i]){
                restart++;
            }
            // } else if(nums[i]-prev>1) {
            //     return false;
            // }
            prev = nums[i];
        }
        
        if(restart>1) return false;
        return true;
    }
};
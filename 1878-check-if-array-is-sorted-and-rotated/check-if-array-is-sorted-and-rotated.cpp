class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int end = nums[n-1];
        int prev = nums[0];
        int restart=0;
        if (end>prev) restart++;
        for(int i=0;i<nums.size();i++){
            if(prev>nums[i]){
                restart++;
            }
            prev = nums[i];
        }
        
        if(restart>1) return false;
        return true;
    }
};
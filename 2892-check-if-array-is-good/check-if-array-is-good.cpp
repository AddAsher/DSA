class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        for(int i =0; i<nums.size(); i++){
            if(i<nums.size()-1){
                if(nums[i]!=i+1)
                    return false;
            } else{
                return nums[i] == nums.size()-1;
            }
        }
        return false;
    }
};
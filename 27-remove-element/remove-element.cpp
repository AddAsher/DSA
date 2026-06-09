class Solution {
public:
    int removeElement(vector<int>& nums, int target) {
        int i =0;
        for(int j =0;j<nums.size();j++){
            if(nums[j]!=target){
                int x = nums[i];
                nums[i]=nums[j];
                nums[j] = x;
                i++;
            }
        }
        return i;
    }
};
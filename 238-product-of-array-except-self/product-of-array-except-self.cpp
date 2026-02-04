class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int prefix = 1;
        //here we do = prefix as all values are equal to 0 when instantiatied.
        for(int i = 0; i<n;i++){
            result[i] = prefix;
            prefix = nums[i] * prefix;
        }

        int suffix = 1;
        for(int i = n-1;i>=0; i--){
            result[i] = result[i] *suffix;
            suffix = suffix * nums[i];
        }
        return result;        
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        bool end = false;
        int left = 0;
        int right = numbers.size() - 1;

        while(left<right){
            int sum = numbers[left] + numbers[right];
            if(sum> target){
                right--;
            } else if (sum< target) {
                left++;                
            } else {
                return {left+1, right+1};
            }

        }

        return {-1,-1};
        //no solution case
    }
};
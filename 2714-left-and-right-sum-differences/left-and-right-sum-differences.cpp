class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), answer(n);

        // left[i] = sum of everything before i
        int sum = 0;
        for (int i = 0; i < n; i++) {
            left[i] = sum;
            sum += nums[i];
        }

        // right[i] = sum of everything after i
        sum = 0;
        for (int i = n-1; i >= 0; i--) {
            right[i] = sum;
            sum += nums[i];
        }

        for (int i = 0; i < n; i++)
            answer[i] = abs(left[i] - right[i]);

        return answer;
    }
};
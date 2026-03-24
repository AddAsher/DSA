class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> times;
        for(int x: nums){
            if(times.count(x)==0) {
                times[x]++;
            }
            else{
                return x;
            }
        }

        return 0;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dups;
        for(int x: nums){
            if(dups[x] !=0)
                return true;
            dups[x]++;
        }
        return false;
    }
};
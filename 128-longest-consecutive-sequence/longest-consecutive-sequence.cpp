class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> count;
        for(int x: nums){
            count[x]=true;
        }
        int maxL = 0;

        for(auto pr: count){
            int num = pr.first;
            if(!count.contains(num-1)){
                int curr = num;
                int len = 1;
                while(count.contains(curr+1)){
                    curr++;
                    len++;
                }
                if(maxL<len){
                    maxL = len;
                }
            }
        }
        return maxL;
        
    }
};
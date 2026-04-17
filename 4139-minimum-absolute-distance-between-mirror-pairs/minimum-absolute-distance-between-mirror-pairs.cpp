class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> dict;
        int minDist = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(dict.count(nums[i])!=0){
                int dist = i - dict[nums[i]];
                minDist = min(dist,minDist);
            }
            dict[reverse(nums[i])]= i;
        }
        return minDist == INT_MAX ? -1 : minDist;
    }

    int reverse(int x){
        int y = 0;
        while(x>0){
            y= y*10;
            int temp = x%10;
            y += temp;
            x= x/10;
        }
        return y;
    }
};
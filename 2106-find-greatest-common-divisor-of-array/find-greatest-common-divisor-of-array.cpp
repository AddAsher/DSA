class Solution {
public:
    int findGCD(vector<int>& nums) {
        int l = -1, s = 1001;
        for(int x: nums){
            if(x>l)
                l=x;
            if(x<s)
                s=x;
        }
        int t = s;
        while(t>1){
            if(l%t==0 && s%t==0)
                break;
            t--;
        }
        return t;        
    }
};
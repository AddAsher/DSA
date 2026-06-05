class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0, j=0; i<nums1.size() && j<nums2.size();){
            int x = nums1[i], y = nums2[j];
            if(x<y){
                i++;
            } else if (x==y){
                return x;
            } else {
                j++;
            }
        }
        return -1;

    }
};
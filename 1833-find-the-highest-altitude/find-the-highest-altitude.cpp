class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int start=0, peak =0;
        for(int x: gain){
            start+=x;
            peak = max(peak, start);
        }
        return peak;
    }
};
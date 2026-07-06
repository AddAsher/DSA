class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];  // if same left, sort by right descending
        return a[0] < b[0];      // sort by left ascending
        });
        
        int count = 0, maxEnd = 0;
        for(auto c: intervals){
            if(c[1]>maxEnd){
                count++;
                maxEnd=c[1];
            }
        }
        return count;
    }
};
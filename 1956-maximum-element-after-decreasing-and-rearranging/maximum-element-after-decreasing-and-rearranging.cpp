class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0]=1;
        int curr = arr[0];
        for(int i =1;i<n; i++){
            if(arr[i]>curr){
                arr[i]=++curr;
            }
        }
        return arr[n-1];
    }
};
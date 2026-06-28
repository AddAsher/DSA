class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return 1;
        }
        sort(arr.begin(), arr.end());
        arr[0]=1;
        int curr = arr[0];
        unordered_map<int,int> freq;
        for(int i =1;i<n; i++){
            if(arr[i]>curr){
                arr[i]=++curr;
            }
        }
        return arr[n-1];
    }
};
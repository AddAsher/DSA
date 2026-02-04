class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()){
            return nums;
        }

        unordered_map<int, int> count;
        for(int x: nums){
            count[x]++;
        }
        //we do a min heap here as we will be able to access the smallest element and pop it out.
        // 1st parameter = type of value that is being compared
        // 2nd parameter = container of all values
        // 3rd parameter = comparison (greater means bigger elements in the back aka minHeap)
        // (less would mean smaller elements pushed back aka maxHeap but this is default)
        // (normal maxHeap is accomplished with priority_queue<pair<int,int>> maxHeap == 
        // priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>> maxHeap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto pr: count){
            minHeap.push({pr.second, pr.first});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;


    }
};
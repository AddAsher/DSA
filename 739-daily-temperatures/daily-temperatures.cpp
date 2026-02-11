class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> results(temps.size());
        stack<int> ind;

        for(int i=0; i<temps.size(); i++){
            while(!ind.empty() && temps[i]>temps[ind.top()]){
                results[ind.top()] = i - ind.top();
                ind.pop();
            }
            ind.push(i);
        }
        return results;
    }
};
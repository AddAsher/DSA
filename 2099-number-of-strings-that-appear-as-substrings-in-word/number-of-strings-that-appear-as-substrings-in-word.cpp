class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int tot=0;
        for(string s: patterns){
            if(word.find(s) != string::npos){
                tot++;
            }
        }
        return tot;
    }
};
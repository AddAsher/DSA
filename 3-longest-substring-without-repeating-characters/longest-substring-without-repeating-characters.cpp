class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int left=0;
        unordered_set<char> dup;

        for(int i=0; i<s.length(); i++){
            while(dup.find(s[i]) != dup.end()){
                dup.erase(s[left]);
                left++;
            }

            dup.insert(s[i]);
            maxlen=max(maxlen, i-left+1);
        }

        return maxlen;                        
    }
};
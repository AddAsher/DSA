class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        int n =s.length();
        unordered_map<char, int> charMap;
        for(int i=0; i<n;i++){
            int freq[26] = {};
            for(int j=i; j<n;j++){
                freq[s[j]-'a']++;
                int maxF=0;
                int minF = INT_MAX;
                for(int k=0; k<26;k++){
                    if (freq[k]>0){
                        maxF = max(maxF, freq[k]);
                        minF = min(minF, freq[k]);
                    }
                }
                if(maxF == minF){
                    maxLen = max(maxLen,j-i+1);
                }
            }            

        }
        return maxLen;
    }
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        const int qz = queries.size(), sz = queries[0].size();
        for(string word: queries){
            for(string dic: dictionary){
                int diff = 0;
                for(int i=0; i<sz;i++){
                    if(word[i]!=dic[i]){
                        diff++;
                        if(diff>2) break;
                    }
                }

                if(diff<=2){
                    ans.push_back(word);
                    break;
                }
            }                                    
        }
        return ans;        
    }
};
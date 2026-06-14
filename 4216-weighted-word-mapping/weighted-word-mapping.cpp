class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int weg=0;
        string res = "";
        for(int i=0; i<words.size();i++){
            for(char s: words[i]){
                weg+= weights[s - 'a'];
            }
            weg = weg%26;
            res+='z'-weg;
            weg=0;
        }
        return res;
    }
};
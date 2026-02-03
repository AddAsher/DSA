class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) 
            return false;
        unordered_map<char, int> dict;
        for(char x: s){
            dict[x]++;
        }
        for(char x: t){
            dict[x]--;
        }

        for(auto& pair : dict){
            if(pair.second != 0)
                return false;
        }
        return true;

    }
};
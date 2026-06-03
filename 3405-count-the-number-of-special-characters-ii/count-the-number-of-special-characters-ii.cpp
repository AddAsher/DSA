class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int, int> lower, upper;
        for(int i =0;i<word.length();i++){
            if(islower(word[i])){
                lower[word[i]-'a'] = i;
            } else{
                char low = tolower(word[i])-'a';
                if(upper.count(low)==0){
                    upper[low]=i;
                }
            }
        }
        int count = 0;
        for(int i =0; i<26;i++){
            if(lower.count(i) && upper.count(i) && lower[i]<upper[i])
            count++;
        }
        return count;
    }
};
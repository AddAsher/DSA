class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> dict;
        for(char c: text){
            dict[c]++;
        }
        string ballon = "balon";
        int mins = INT_MAX;

        for(int i = 0; i<5;i++){
            char c = ballon[i];
            int num = dict[c];
            if(c=='l' || c =='o') num/=2;
            mins = min(mins, num);
        }
        return mins;
    }
};
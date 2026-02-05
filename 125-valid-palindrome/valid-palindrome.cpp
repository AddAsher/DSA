class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(int i=0; i<s.length();i++){
            if(isalnum(s[i])){
                result += tolower(s[i]);
            }
        }
        int len = result.length();
        for(int i =0; i<len/2;i++){
            if(result[i] != result[len-i-1])
                return false;
        }
        return true;
    }
};
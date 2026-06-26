class Solution {
public:
    int myAtoi(string s) {
        int num=0, ind = 0, n = s.length();
        int sign = 1;
        if(n==0) return 0;

        while(ind < n && s[ind] == ' ') ind++;

        if (ind == n) {
            return 0;
        }

        if (s[ind]=='-'){
            ind++;
            sign = -1;
        } else if(s[ind]=='+'){
            ind++;
        }
        
        while(ind<n && isdigit(s[ind])){
            int digit = s[ind] - '0';
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) return sign == 1 ? INT_MAX : INT_MIN;
            num = num*10 + digit;
            ind++;
        }
        return num*sign;
        
    }
};
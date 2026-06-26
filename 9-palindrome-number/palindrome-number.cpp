class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y = x;
        long res = 0;
        while(y>0){
            res = res*10 + y%10;
            y /=10;
        }
        return x == res;        
    }
};
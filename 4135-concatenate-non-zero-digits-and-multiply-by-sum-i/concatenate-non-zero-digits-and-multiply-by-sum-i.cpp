class Solution {
public:
    long long sumAndMultiply(int n) {
        int res = 0, sum=0, len=1;
        while(n>0){
            int t = n%10;
            n/=10;
            if(t>0){
                res+=t*len;
                len*=10;
            }
            sum+=t;
        }
        return (long)res*sum;
    }
};
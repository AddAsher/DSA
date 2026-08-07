class Solution {
public:
    int smallestNumber(int n, int t) {
        while(getProd(n)%t!=0){
            n++;
        }
        return n;
    }

    int getProd(int n){
        int r=1;
        while(n>0){
            r*=n%10;
            n/=10;
        }
        return r;
    }
};
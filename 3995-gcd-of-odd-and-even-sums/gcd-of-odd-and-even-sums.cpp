class Solution {
public:
    int gcdOfOddEvenSums(int n) {
     int oddSum = 0, evenSum = 0;
     int oddNum = 1, evenNum = 2;
        for(int i =0; i<n; i++){
            evenSum+=evenNum;
            oddSum+=oddNum;
            evenNum+=2;

            oddNum+=2;
        }

        int t = min(oddSum, evenSum);
        while(t>1){
            if(oddSum%t==0 && evenSum%t==0){
                break;
            }
            t--;
        }

        return t;
       
    }
};
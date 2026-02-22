class Solution {
public:
    int binaryGap(int n) {
        string binary = "";
        while(n>0){
            if(n%2==0){
                binary = "0" + binary;
            } else {
                binary = "1" + binary;
            }
            n/=2;
        }
        cout<<binary;

        int ans = 0;
        int indx = binary.find("1");
        for(int i = 0; i< binary.size();i++){
            if(binary[i] == '1'){
                ans = max(ans, i - indx);
                indx = i;
            }
        }
        return ans;
    }
};
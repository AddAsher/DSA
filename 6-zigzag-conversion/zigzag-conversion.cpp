class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        if (numRows==1) return s;
        int n = s.length();
        for(int i =0;i<numRows;i++){
            int pos = i;
            int cycle = (numRows - 1) * 2;
            while (pos<n){
                ans+=s[pos];
                int diag = pos + cycle - 2*i;
                if((i!=0 && i!=(numRows-1)) && diag<n){
                    ans+=s[diag];
                }
                pos+=cycle;
            }
        }
        return ans;
    }
};
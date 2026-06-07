class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(char c : moves){
            if(c=='R')
                x++;
            else if(c=='L'){
                x--;
            } else if(c=='U'){
                y++;
            } else {
                y--;
            }
        }
        return abs(x)+abs(y) == 0;
        
    }
};
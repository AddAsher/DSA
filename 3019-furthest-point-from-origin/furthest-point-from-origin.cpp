class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist=0, free=0;
        for(int i =0; i<moves.length();i++){
            if(moves[i]=='_'){
                free++;
            }else if(moves[i]=='R'){
                dist++;
            } else {
                dist--;
            }
        }
        return abs(dist) + free;
        
    }
};
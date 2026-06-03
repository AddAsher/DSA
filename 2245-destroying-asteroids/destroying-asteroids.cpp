class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end(), less<int>());
        long long res = mass;
        for(int as: asteroids){
            if(res>=as){
                res+= as;
            }else{
                return false;
            }
            
        }
        return true;        
    }
};
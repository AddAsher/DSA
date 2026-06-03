class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end(), less<int>());
        long long res = mass;
        for(int i = 0; i<asteroids.size();i++){
            if(res>=asteroids[i]){
                res+= asteroids[i];
            }else{
                return false;
            }
            
        }
        return true;        
    }
};
class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(begin(asteroids),end(asteroids));
        for(auto &i:asteroids){
            if(i>mass){ return false; }
            mass+=i;
        }
        return true;
    }
};
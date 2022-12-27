class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
         vector<int> v; 
         for(int i = 0 ; i < capacity.size(); i ++ ) {
              v.push_back(capacity[i] - rocks[i]); 
         }
         sort(v.begin(), v.end()); 
         int  cnt = 0 ; 
         for(auto a : v){
            if(a == 0){ cnt++; }
            else if(additionalRocks-a>=0){
                  cnt++; 
                  additionalRocks-=a; 
              }
         }
         return cnt ; 
    }
};
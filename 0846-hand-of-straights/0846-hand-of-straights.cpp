class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto &i:hand){ mp[i]++; }
        for(auto &[i,freq]:mp){
            if(freq>0){
                for(int j=i+groupSize-1; j>=i; j--){
                    mp[j]-=freq;
                    if(mp[j]<0){ return false; }
                }
            }
        }
        return true;
    }
};
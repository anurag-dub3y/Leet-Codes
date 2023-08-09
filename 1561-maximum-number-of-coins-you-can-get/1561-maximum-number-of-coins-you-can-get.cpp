class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles),end(piles));
        int ans=0, j=0;
        for(int i=piles.size()-2; i>=0 && j<piles.size()/3; i-=2){
            ans+=piles[i]; j++;
        }        
        return ans;
    }
};


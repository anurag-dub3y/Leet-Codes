class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal=prices[0], ans=0;
        for(int i=1; i<size(prices); i++){
            if(prices[i]>minVal){
                ans+=(prices[i]-minVal);
                minVal=prices[i];
            }
            else{ minVal=prices[i]; }
        }
        return ans;
    }
};
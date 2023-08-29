class Solution {
public:
    int n;
    unordered_map<string,int> dp;
    int find(int i, vector<int>& price, vector<vector<int>>& special, string &reqd){
        // Buy some from special[] and rest at price[i]
        if(i==special.size()){
            int curr=0;
            for(int j=0; j<reqd.size(); j++){
                curr+=(reqd[j]-'0')*price[j];
            }
            return curr;
        }
        string hsh=reqd+'_'+to_string(i);
        if(dp.count(hsh)){ return dp[hsh]; }
        int ans=find(i+1,price,special,reqd);
        bool canTake=true;
        for(int k=1; k<=50; k++){
            string tmp=reqd;
            for(int j=0; j<n; j++){
                if(tmp[j]-'0'<k*special[i][j]){
                    canTake=false; break;
                }
                else{ tmp[j]-=k*special[i][j]; }
            }
            if(canTake){
                ans=min(ans,k*special[i].back()+find(i+1,price,special,tmp));
            }
            else{
                break;
            }
        }
        return dp[hsh]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=price.size();
        string reqd="";
        for(auto &i:needs){
            reqd+=(char)('0'+i);
        }
        return find(0,price,special,reqd);
    }
};
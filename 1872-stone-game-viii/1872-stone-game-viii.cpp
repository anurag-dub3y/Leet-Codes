class Solution {
public:
    int dp[1000002][2];
    int inf=1e9;
    int findDiff(int i, int chance, vector<int>& pre){
        if(i>=pre.size()){ return 0; }
        if(i==pre.size()-1){ return chance==0?pre[i]:-pre[i]; }
        int &val=dp[i][chance];
        if(val!=-1){ return val; }
        if(chance==0){
            val=max(pre[i]+findDiff(i+1,!chance,pre),findDiff(i+1,chance,pre));
        }
        else{
            val=min(-pre[i]+findDiff(i+1,!chance,pre),findDiff(i+1,chance,pre));           
        }
        return val;
    }
    int stoneGameVIII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        vector<int> pre={0};
        for(auto &s:stones){
            pre.push_back(pre.back()+s);
        }
        return findDiff(2,0,pre);
    }
};
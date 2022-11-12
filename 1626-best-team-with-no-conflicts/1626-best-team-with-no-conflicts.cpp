class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++){ v[i]={ages[i],scores[i]}; }
        sort(v.begin(),v.end());
        vector<int> dp(n,0);
        for(int i=0; i<n; i++){
            dp[i]=v[i].second;
            for(int j=i-1; j>=0; j--){
                if(v[i].second>=v[j].second){ dp[i]=max(dp[i],dp[j]+v[i].second); }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
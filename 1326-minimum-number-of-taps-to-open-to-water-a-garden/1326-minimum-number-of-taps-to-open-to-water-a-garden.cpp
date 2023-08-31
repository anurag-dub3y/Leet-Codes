class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> vp(n+1);
        for(int i=0; i<ranges.size(); i++){ vp[i]={i-ranges[i],i+ranges[i]}; }
        sort(begin(vp),end(vp),[&](pair<int,int> &p1, pair<int,int> &p2){
            if(p1.first!=p2.first){ return p1.first<p2.first; }
            return p1.second<p2.second;
        });
        // map<int,int> dp;
        vector<int> dp(n+2,1e9);
        // dp[0]=1;
        int ans=INT_MAX, prev=0;
        // dp[vp[0].first]=0;
        for(int i=0; i<=n; i++){
            auto [st,end]=vp[i];
            // dp[end]=1e4+4;
            // auto it=dp.lower_bound(st);
            // while(it!=dp.end()){    // Will run at max 100 times since ranges[i]<=100
            //     dp[end]=min(dp[end],1+it->second);
            //     it++;
            // }
            if(st<=0){ dp[i]=1; }
            for(int j=i-1; j>=0; j--){
                if(vp[j].second>=st){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
            // if(end>=n){ ans=min(ans,dp[end]); }
            if(end>=n){ ans=min(ans,dp[i]); }
            // cout<<dp[i]<<' ';
        }
        return ans>=1e9?-1:ans;
    }
};
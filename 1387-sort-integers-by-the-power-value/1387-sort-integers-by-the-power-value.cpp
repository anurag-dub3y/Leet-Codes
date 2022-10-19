class Solution {
public:
    unordered_map<int,int> dp;
    int dfs(int i){
        if(i==1){ return 0; }
        if(dp.find(i)==dp.end()){
            if(i%2==0){ dp[i]=1+dfs(i/2); }
            else{ dp[i]=1+dfs(3*i+1); }
        }
        return dp[i];
    }
    int getKth(int lo, int hi, int k) {
        vector<int> v;
        for(int i=lo; i<=hi; i++){ dfs(i); v.push_back(i); }
        sort(v.begin(),v.end(),[&](const int &a, const int &b){
            return dp[a]==dp[b]?a<b:dp[a]<dp[b];
        });
        return v[k-1];
    }
};
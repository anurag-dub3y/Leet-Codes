int dp[1001][1001];
class Solution {
public:
    vector<int> pre={0};
    int n;
    int find(int i, int numCarpets, int carpetLen, string &s){
        if(i>=n){ return 0; }
        if(numCarpets==0){ return pre.back()-pre[i]; }
        if(dp[i][numCarpets]!=-1){ return dp[i][numCarpets]; }
        long long ans1=s[i]-'0'+find(i+1,numCarpets,carpetLen,s);
        long long ans2=find(i+carpetLen,numCarpets-1,carpetLen,s);
        // cout<<i<<' '<<ans1<<' '<<ans2<<endl;
        return dp[i][numCarpets]=min(ans1,ans2);
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp,-1,sizeof(dp));
        for(auto i:floor){
            pre.push_back(pre.back()+(i-'0'));
        }
        n=floor.length();
        return find(0,numCarpets,carpetLen,floor);
    }
};
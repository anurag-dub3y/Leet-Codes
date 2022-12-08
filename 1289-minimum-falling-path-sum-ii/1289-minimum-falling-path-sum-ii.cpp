class Solution {
public:
    #define pii pair<int,int>
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){ dp[0][i]=mat[0][i]; pq.push({mat[0][i],i}); }
        for(int i=1; i<n; i++){
            priority_queue<pii,vector<pii>,greater<pii>> temp;
            for(int j=0; j<n; j++){
                pii peak=pq.top(); pq.pop();
                pii x={0,-1};
                int mnVal=peak.first;
                if(peak.second==j){
                    x=pq.top(); pq.pop();
                    mnVal=x.first;
                }
                dp[i][j]=mat[i][j]+mnVal;
                temp.push({dp[i][j],j});
                pq.push(peak);
                if(x.second!=-1){ pq.push(x); }
            }
            swap(pq,temp);
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
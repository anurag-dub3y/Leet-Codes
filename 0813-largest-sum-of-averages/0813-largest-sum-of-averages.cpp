class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> sum(n+1,0.0);
        for(int i=1; i<=n; i++){
            sum[i]=nums[i-1]+sum[i-1];
        }
        if(k<=1){ return (1.0*sum[n])/n; }
        if(k>=n){ return sum[n]; }
        vector<vector<double>> dp(n+1,vector<double>(k+1,0.0));
        for(int i=1; i<=n; i++){
            dp[i][1]=(double)(1.0*sum[i]/i);
            // cout<<dp[i][1]<<endl;
        }
        for(int p=2; p<=k; p++){
        	for(int i=p; i<=n; i++){
        		for(int j=i-1; j>=p-1; j--){
        			dp[i][p] = max(dp[i][p], dp[j][p-1] + 1.0*(sum[i]-sum[j])/(i-j));
        		}
        		
        	}
        }
        return dp[n][k];
    }
};
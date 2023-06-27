class Solution {
public:
    int mx[41][41];
    int dp[41][41];
    int find(int left,int right){
        if(left==right){ return 0; }
        if(dp[left][right]!=-1){ return dp[left][right]; }
        int ans = INT_MAX;
        for(int i=left; i<right; i++){
            ans= min(ans, mx[left][i] * mx[i+1][right] + find(left,i) + find(i+1,right) );
        }
        return dp[left][right]=ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<arr.size(); i++){
            mx[i][i] = arr[i];
            for(int j=i+1; j<arr.size(); j++){
                mx[i][j] = max(mx[i][j-1], arr[j]);
            }
        }
        return find(0,arr.size()-1);
    }
};
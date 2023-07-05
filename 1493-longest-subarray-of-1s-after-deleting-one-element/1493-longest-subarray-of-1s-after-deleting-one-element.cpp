class Solution {
public:
    // int dp[100005][2];
    // int find(int i, vector<int>& nums, int last){
    //     if(i==nums.size()){ return 0; }
    //     if(dp[i][last]!=-1){ return dp[i][last]; }
    //     if(last==1){
    //         int len=0;
    //         while(i<nums.size() and nums[i++]==1){ len++; }
    //         dp[i][last]=len;
    //     }
    //     else{
    //         if(nums[i]==1){ dp[i][last]=1+find(i+1,nums,0); }
    //         else{
    //             // We can delete nums[i] with ans1 or we can start new one
    //             int ans1=find(i+1,nums,1), ans2=find(i+1,nums,0);
    //             dp[i][last]=max(ans1,ans2);
    //         }
    //     }
    //     return dp[i][last];
    // }
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(*max_element(nums.begin(),nums.end())==1 && *min_element(nums.begin(),nums.end())==1){ return n-1; }
        int ans=0;
        // memset(dp,-1,sizeof(dp));
        // return find(0,nums,0);
        map<int,int> mp;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){ cnt++; }
            else{ mp[i]=cnt; cnt=0; }
        }
        cnt=0;
        for(int i=n-1; i>=0; i--){
            if(nums[i]==1){ cnt++; }
            else{
                ans=max(ans,mp[i]+cnt);
                cnt=0;
            }
        }
        return ans;
    }
};
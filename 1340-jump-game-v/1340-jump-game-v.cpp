class Solution {
public:
    // Store all the peaks then simulate for each peak
    int dp[1003];
    int find(int i, int d, vector<int>& arr){
        if(dp[i]){ return dp[i]; }
        int f=i-1, b=i+1, ans=0;
        while(f>=0 and i-f<=d and arr[f]<arr[i]){ ans=max(ans,find(f,d,arr)); f--; }
        while(b<arr.size() and b-i<=d and arr[b]<arr[i]){ ans=max(ans,find(b,d,arr)); b++; }
        return dp[i]=1+ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();        
        memset(dp,0,sizeof(dp));
        for(int i=0; i<arr.size(); i++){
            find(i,d,arr);
        }
        return *max_element(dp,dp+1002);
    }
};
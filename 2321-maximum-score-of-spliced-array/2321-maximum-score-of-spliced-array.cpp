class Solution {
public:
//     int dp[100001][3];
//     int find(int i, int state, vector<int>& nums1, vector<int>& nums2){
//         if(i==nums1.size()){ return 0; }
//         cout<<i<<' '<<nums1[i]<<' '<<state<<endl;
//         if(dp[i][state]!=-1){ return dp[i][state]; }
        
//         int ans=INT_MIN, sum=0;
//         if(state==0){
//             for(int j=i; j<nums1.size(); j++){
//                 sum+=nums1[j];
//                 ans=max(ans,sum+find(j+1,1,nums1,nums2));
//             }
//         }
//         else if(state==1){
//             // cout<<"Yay!"<<' ';
//             for(int j=i+1; j<nums1.size(); j++){
//                 sum+=nums2[j];
//                 // cout<<i<<' '<<sum<<endl;
//                 ans=max(ans,sum+find(j+1,2,nums1,nums2));
//             }
//         }
//         else if(state==2){ 
//             ans=0;
//             while(i<nums1.size()){ ans+=nums1[i++]; }
//         }
//         return dp[i][state]=ans;
//     }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        // vector<int> pre1={0}, pre2={0};
        // for(int i=0; i<n; i++){
        //     pre1.push_back(pre1.back()+nums1[i]);
        //     pre2.push_back(pre2.back()+nums2[i]);
        // }
        // int ans=INT_MIN;
        // for(int i=1; i<=n; i++){
        //     for(int j=0; i+j<=n; j++){
        //         int sum1=pre1.back()-(pre1[i+j]-pre1[i-1])+(pre2[i+j]-pre2[i-1]);
        //         int sum2=pre2.back()-(pre2[i+j]-pre2[i-1])+(pre1[i+j]-pre1[i-1]);
        //         ans=max({ans,sum1,sum2});
        //     }
        // }
        // memset(dp,-1,sizeof(dp));
        // int ans1=find(0,0,nums1,nums2);
        // memset(dp,-1,sizeof(dp));
        // int ans2=find(0,0,nums2,nums1);
        // return max(ans1,ans2);
        vector<vector<int> > dp1(n + 1, vector<int>(3, 0));
        vector<vector<int> > dp2(n + 1, vector<int>(3, 0));
        for (int i = 1 ; i <= n ; i++){
            
            // For 1st array with subarray from 2nd array
            dp1[i][0] = dp1[i - 1][0] + nums1[i - 1];
            dp1[i][1] = max(dp1[i - 1][1], dp1[i - 1][0]) + nums2[i - 1];
            dp1[i][2] = max(dp1[i - 1][1], dp1[i - 1][2]) + nums1[i - 1];
            
            // For 2nd array with subarray from 1st array
            dp2[i][0] = dp2[i - 1][0] + nums2[i - 1];
            dp2[i][1] = max(dp2[i - 1][1], dp2[i - 1][0]) + nums1[i - 1];
            dp2[i][2] = max(dp2[i - 1][1], dp2[i - 1][2]) + nums2[i - 1];
        }
        return max({dp1[n][0], dp1[n][1], dp1[n][2], dp2[n][0], dp2[n][1], dp2[n][2]});
    }
};
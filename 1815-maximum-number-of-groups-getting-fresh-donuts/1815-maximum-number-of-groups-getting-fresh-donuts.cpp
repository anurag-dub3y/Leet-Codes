// int dp[1<<24][10];
// class Solution {
// public:
//     int n;
//     int findMax(int mask, int prev, int batchSize, vector<int>& groups){
//         if(mask==((1<<n)-1)){ return 0; }
//         int &ans=dp[mask][prev];
//         if(ans!=-1){ return ans; }
//         for(int i=0; i<n; i++){
//             if((mask>>i)&1){ continue; }
//             if(prev==0){
//                 ans=max(ans,1+findMax(mask|(1<<i),groups[i],batchSize,groups));
//             }
//             else{
//                 ans=max(ans,findMax(mask|(1<<i),(prev+groups[i])%batchSize,batchSize,groups));
//             }
//         }
//         return ans;
//     }
//     int maxHappyGroups(int batchSize, vector<int>& groups) {
//         for(auto &i:groups){ i%=batchSize;  } 
//         this->n=groups.size();
//         memset(dp,-1,sizeof(dp));
//         return findMax(0,0,batchSize,groups);
//     }
// };
class Solution {
public:
    int maxHappyGroups(int bs, vector<int>& groups) {
        vector<int> freq(bs, 0);
        long long sum = 0;
        for(auto it : groups){   
            freq[it%bs]++; 
            sum += it;
        }
        map<vector<int>, int> dp;
        int ans = freq[0] + (sum%bs != 0);

        for(int i = 1 ; i < bs ; i++){
            if(i != bs-i){
                ans += min(freq[i], freq[bs-i]);
                int temp = min(freq[i], freq[bs-i]);
                freq[i] -= temp;
                freq[bs-i] -= temp;
            }
        }
        return maxGroups(bs, freq, 0, dp) + ans;
    }

    int maxGroups(int bs, vector<int>& freq, int rem, map<vector<int>, int>& dp){
        int ans = 0;
        if(dp.count(freq)){ return dp[freq]; }
        for(int i = 1 ; i < bs ; i++){
            if(freq[i] > 0){
                freq[i]--;
                ans = max(ans, ((rem+i)%bs == 0) + maxGroups(bs, freq, (rem+i)%bs, dp));
                freq[i]++;
            }
        }
        return dp[freq] = ans;
    }
};
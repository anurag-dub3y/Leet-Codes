class Solution {
public:
//     int overlap[12][12], n;
//     string dp[12][1<<12];
//     string findMxOverlap(int i, int mask, string &curr, vector<string>& words){
//         if(mask==((1<<n)-1)){ return curr;  }
//         if(dp[i][mask]!=""){ return dp[i][mask]; }
//         string ans=""; int mnLen=1e9;
//         for(int j=0; j<n; j++){
//             if((mask>>j)&1){ continue; }
//             string prev=curr;
//             curr=curr+words[j].substr(overlap[i][j]);
//             string newLen=findMxOverlap(j,mask|(1<<j),curr,words);
//             if(newLen.length()<mnLen){
//                 ans=newLen;
//                 mnLen=newLen.length();
//             }
//         }
//         return dp[i][mask]=ans;
//     }
//     string shortestSuperstring(vector<string>& words) {
//         n=words.size();
//         int wordLenSum=0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<(1<<n); j++){ dp[i][j]=""; }
//         }        
//         for(int i=0; i<words.size(); i++){
//             wordLenSum+=words[i].size();
//             for(int j=0; j<words.size(); j++){
//                 int i1=words[i].length()-1, i2=0;
//                 while(i1>=0 and i2<=words[j].length()-1 and words[i][i1--]==words[j][i2++]){
//                     overlap[i][j]++;
//                 }
//             }
//         }
//         string ans=""; int mnLen=1e9;
//         for(int i=0; i<n; i++){
//             string tmp=findMxOverlap(i,(1<<i),words[i],words);
//             if(tmp.length()<mnLen){
//                 mnLen=tmp.length(); ans=tmp;
//             }
//         }
//         return ans;
//     }
// };
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        // dp[mask][i] : min superstring made by strings in mask,
        // and the last one is A[i]
        vector<vector<string>> dp(1<<n,vector<string>(n));
        vector<vector<int>> overlap(n,vector<int>(n,0));
        
        // 1. calculate overlap for A[i]+A[j].substr(?)
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(i!=j){
            for(int k = min(A[i].size(), A[j].size()); k>0; --k)
                if(A[i].substr(A[i].size()-k)==A[j].substr(0,k)){
                    overlap[i][j] = k; 
                    break;
                }
        }
        // 2. set inital val for dp
        for(int i=0; i<n; ++i) dp[1<<i][i] += A[i];
        // 3. fill the dp
        for(int mask=1; mask<(1<<n); ++mask){
            for(int j=0; j<n; ++j) if((mask&(1<<j))>0){
                for(int i=0; i<n; ++i) if(i!=j && (mask&(1<<i))>0){
                    string tmp = dp[mask^(1<<j)][i]+A[j].substr(overlap[i][j]);
                    if(dp[mask][j].empty() || tmp.size()<dp[mask][j].size())
                        dp[mask][j] = tmp;
                }
            }
        }
        // 4. get the result
        int last = (1<<n)-1;
        string res = dp[last][0];
        for(int i=1; i<n; ++i) if(dp[last][i].size()<res.size()){
            res = dp[last][i];
        }
        return res;
    }
};
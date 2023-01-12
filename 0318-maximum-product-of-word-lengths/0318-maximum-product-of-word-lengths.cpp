class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0, n=words.size();
        vector<vector<int>> f(n,vector<int>(26,0));
        for(int i=0; i<n; i++){
            for(auto j:words[i]){ f[i][j-'a']++; }
        }
        for(int i=0; i<n; i++){
            int p=words[i].length();
            for(int j=i+1; j<n; j++){
                int q=words[j].length();
                int k=0;
                for(int r=0; r<26; r++){ if(f[i][r]!=0 and f[j][r]!=0){ k=1; } }
                if(k==0){
                    ans=max(ans,p*q);
                }
            }
        }
        return ans;
    }
};
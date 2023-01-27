class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> s(words.begin(),words.end());
        for(auto w:words){
            int n=w.length();
            vector<int> dp(n+1,0); dp[0]=1;
            for(int i=0; i<n; i++){
                if(dp[i]==0){ continue; }
                for(int j=i+1; j<=n and j-i<n; j++){
                    string tmp=w.substr(i,j-i);
                    if(s.find(tmp)!=s.end()){
                        dp[j]=1;
                    }
                }
                if(dp[n]){ ans.push_back(w); break; }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int find(unordered_map<string, int>& dp, vector<vector<int>>& mp, string target) {
        if(dp.count(target)){ return dp[target]; }
        int ans = INT_MAX, n = mp.size();
        vector<int> tar(26, 0);
        for(auto c:target){ tar[c-'a']++; }
        for (int i = 0; i < n; i++) {
            if (mp[i][target[0]-'a'] == 0){ continue; }
            string s="";
            for (int j = 0; j < 26; j++){
                if (tar[j]-mp[i][j]>0){ s += string(tar[j]-mp[i][j], 'a'+j); }
            }
            int tmp=find(dp,mp,s);
            if(tmp!=-1){ ans=min(ans,1+tmp); }
        }
        dp[target] = ans==INT_MAX?-1:ans;
        return dp[target];
    }
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        unordered_map<string, int> dp;
        for (int i = 0; i < m; i++) {
            for (auto &c:stickers[i]){ mp[i][c-'a']++; }
        }
        dp[""] = 0;
        return find(dp, mp, target);
    }
};
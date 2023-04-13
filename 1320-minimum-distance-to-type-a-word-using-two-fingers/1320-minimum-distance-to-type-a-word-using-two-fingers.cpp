class Solution {
public:
    map<char,pair<int,int>> mp;
    int dp[303][37][37];
    int dist(int i, string &word, pair<int,int> lastL, pair<int,int> lastR){
        if(i==word.size()){ return 0; }
        int l=lastL.first*6+lastL.second, r=lastR.first*6+lastR.second;
        if(dp[i][l][r]!=-1){ return dp[i][l][r]; }
        int ans=INT_MAX;
        int x=mp[word[i]].first, y=mp[word[i]].second;
        int rD=(lastR.first==6)?0:abs(x-lastR.first)+abs(y-lastR.second);
        int lD=(lastL.first==6)?0:abs(x-lastL.first)+abs(y-lastL.second);
        ans=min(rD+dist(i+1,word,lastL,{x,y}),lD+dist(i+1,word,{x,y},lastR));
        return dp[i][l][r]=ans;
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<26; i++){
            mp['A'+i]={i/6,i%6};
        }
        return dist(0,word,{6,0},{6,0});
    }
};

// 00 01 02 03 04 05
// 10 11 12 13 14 15
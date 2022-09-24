class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=0;
        for(auto s:sentences){
            stringstream ss(s);
            string word;
            int cnt=0;
            while(ss>>word){
                cnt++;
            }
            mx=max(cnt,mx);
        }
        return mx;
    }
};
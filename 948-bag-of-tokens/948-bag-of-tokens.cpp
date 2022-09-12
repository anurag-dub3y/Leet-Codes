class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int start = 0, end = tokens.size() - 1;
        int ans=0, score=0;
        while(start<=end){
            if(power>=tokens[start]){
                score++; power-=tokens[start++];
                ans=max(ans,score);
            }
            else if(score>=1){
                score--;
                power+=tokens[end--];
            }
            else{ return ans; }
        }
        return ans;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0, n=cardPoints.size(), s=0;
        for(int i=n-k; i<n; i++){ ans+=cardPoints[i]; }
        for(int i=0, s=ans; i<k; i++) {
            s-=cardPoints[n-k+i];
            s+=cardPoints[i];
            ans=max(ans,s);
        }
        return ans;
    }
};
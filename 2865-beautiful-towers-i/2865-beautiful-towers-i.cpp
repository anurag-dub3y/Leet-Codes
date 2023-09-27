class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        long long ans=0;
        for(int i=0; i<h.size(); i++){
            long long curr=h[i], prev=h[i];
            for(int j=i-1; j>=0; j--){
                prev=min(prev,1LL*h[j]);
                curr+=prev;
            }
            prev=h[i];
            for(int j=i+1; j<h.size(); j++){
                prev=min(prev,1LL*h[j]);
                curr+=prev;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};
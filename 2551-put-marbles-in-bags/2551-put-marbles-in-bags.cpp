class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(k==1){ return 0; }
        vector<int> pairs;
        for(int i=0; i<weights.size()-1; i++){
            pairs.push_back(weights[i]+weights[i+1]);
        }
        sort(pairs.begin(), pairs.end());
        long long minScore=0, maxScore= 0;
        for(int i=0; i<k-1; i++){
            minScore+=pairs[i];
            maxScore+=pairs[n-2-i];
        }
        return maxScore-minScore;
    }
};
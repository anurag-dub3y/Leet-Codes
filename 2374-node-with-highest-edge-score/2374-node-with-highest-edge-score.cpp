class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,long long> scores;
        for(int i=0; i<edges.size(); i++){
            scores[edges[i]]+=i;
        }
        long long ans=0, mx=0;
        for(int i=0; i<edges.size(); i++){
            if(scores[i]>mx){
                mx=scores[i]; ans=i;
            }
        }
        return ans;
    }
};
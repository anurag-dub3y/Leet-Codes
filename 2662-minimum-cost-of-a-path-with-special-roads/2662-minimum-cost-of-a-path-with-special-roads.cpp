typedef vector<int> vii;
typedef pair<int,int> pii;
typedef priority_queue<pii,vector<pii>,greater<pii>> minheap;
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& roads) {
        minheap pq;
        int n=roads.size();
        vii dp(n,1e9);
        for(int i=0; i<n; i++){
            pq.push({abs(start[0]-roads[i][0])+abs(start[1]-roads[i][1])+roads[i][4],i});
        }
        while(!pq.empty()){
            auto [d,i]=pq.top(); pq.pop();
            if(dp[i]!=1e9){ continue; }
            dp[i]=d;
            for(int j=0; j<n; j++){
                if(j==i){ continue; }
                int cost=abs(roads[i][2]-roads[j][0])+abs(roads[i][3]-roads[j][1])+roads[j][4];
                pq.push({d+cost,j});
            }
        }
        int ans=abs(start[0]-target[0])+abs(start[1]-target[1]);
        for(int i=0; i<n; i++){
            ans=min(ans,dp[i]+abs(roads[i][2]-target[0])+abs(roads[i][3]-target[1]));
        }
        return ans;
    }
};
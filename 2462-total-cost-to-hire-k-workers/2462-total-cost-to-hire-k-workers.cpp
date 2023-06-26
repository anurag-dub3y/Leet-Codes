class Solution {
public:
    #define pii pair<int,int>
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        long long ans=0; int st=candidates, end=costs.size()-candidates-1;
        for(int i=0; i<candidates; i++){ pq.push({costs[i],i}); }
        for(int i=costs.size()-1; i>=costs.size()-candidates and i>=st; i--){ pq.push({costs[i],i}); }
        while(k--){
            // cout<<ans<<' ';
            pii x=pq.top(); pq.pop();
            ans+=x.first; 
            if(st>end){ continue; }
            if(x.second<st){ pq.push({costs[st],st++}); }
            else if(x.second>=end){ pq.push({costs[end],end--}); }
        }
        return ans;
    }
};
class Solution {
public:
    typedef long long ll;
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        ll n=chargeTimes.size();
        deque<ll> dq;
        ll ans=0, currSum=0, i=0, j=0;
        for(int i=0; i<chargeTimes.size(); i++){
            currSum+=runningCosts[i];
            while(!dq.empty() && chargeTimes[dq.back()]<=chargeTimes[i]){ dq.pop_back(); }
            dq.push_back(i);
            while(!dq.empty() && j<=i && currSum*(i-j+1)+chargeTimes[dq.front()]>budget){
                if(dq.front()==j){ dq.pop_front(); }
                currSum-=runningCosts[j++];
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
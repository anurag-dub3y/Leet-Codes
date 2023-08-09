class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(), i=0, ans=1e6;
        long long sum=0;
        deque<pair<long long,int>> dq;
        while(i<n){
            sum+=nums[i];
            if(sum>=k){ ans=min(ans,i+1); }
            while(!dq.empty() and sum-dq.front().first>=k){
                ans=min(ans,i-dq.front().second);
                dq.pop_front();
            }            
            while(!dq.empty() and sum<dq.back().first){ dq.pop_back(); }
            dq.push_back({sum,i});
            i++;
        }
        return ans==1e6?-1:ans;
    }
};
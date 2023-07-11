class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0, curr=0;
        int ans=0;
        priority_queue<double> pq;
        for(auto &i:nums){
            pq.push((double)i); sum+=i;
        }
        while(curr<(sum/2.0)){
            ++ans;
            double i=pq.top(); pq.pop();
            curr+=i/2.0; pq.push(i/2.0);
        }
        return ans;
    }
};
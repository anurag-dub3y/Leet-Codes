class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int sum=0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    if(pq.top().first>sum){
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                    else{
                        break;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while(k-- and !pq.empty()){
            auto val = pq.top();
            int x = val.second.first;
            int y = val.second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};
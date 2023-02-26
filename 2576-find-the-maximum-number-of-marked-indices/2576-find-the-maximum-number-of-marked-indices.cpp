class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        multiset<int> low, high;
        int cnt=0, n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n/2; i++){ low.insert(nums[i]); }
        for(int i=n/2; i<n; i++){ high.insert(nums[i]); }
        for(auto it=low.begin(); it!=low.end(); ++it){
            int val=*it; val*=2;
            auto jt=high.lower_bound(val);
            if(jt==high.end() or val>(*jt)){ break; }
            else{ 
                // cout<<minNum<<' '<<*jt<<'\n';
                high.erase(jt); cnt+=2; 
            }
        }
        return cnt;
    }
};


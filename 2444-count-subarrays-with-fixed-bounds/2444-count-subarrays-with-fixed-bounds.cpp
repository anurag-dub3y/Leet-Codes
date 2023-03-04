class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        set<int> s, gr, sm;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minK or nums[i]>maxK){ s.insert(i); }
            if(nums[i]==minK){ sm.insert(i); }
            if(nums[i]==maxK){ gr.insert(i); }
        }
        s.insert(nums.size()); gr.insert(nums.size()); sm.insert(nums.size());
        int i=0;
        while(i<nums.size()){
            if(s.find(i)==s.end()){
                int low=max(*sm.lower_bound(i),*gr.lower_bound(i));
                int hi=*s.lower_bound(i);
                if(hi>low){ ans+=hi-low; }
            }
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target, int ind) {
        vector<vector<int>> v;
        int n=nums.size();
        if(n<3){ return v; }
        for(int i=ind; i<n-2; i++){
            if(i==ind or nums[i]!=nums[i-1]){
                int f=n-1, b=i+1;
                while(b<f && f>=0 && b>=0 && f<n && b<n){
                    long long sum=1LL*nums[f]+1LL*nums[b]+1LL*nums[i]+1LL*nums[ind-1];
                    if(sum>(long long)target){ f--; }
                    else if(sum<target){ b++; }
                    else{ 
                        vector<int> z={nums[i],nums[b],nums[f],nums[ind-1]};
                        v.push_back(z); 
                        while (b < f && nums[b] == nums[b+1]) b++;
                        while (b < f && nums[f] == nums[f-1]) f--;
                        b++; f--;
                    }
                }
            }
        }
        return v;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){ return {}; }
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-3; i++){
            if(i>0 and nums[i]==nums[i-1]){ continue; }
            vector<vector<int>> k=threeSum(nums,target,i+1);
            if(k.size()==0){ continue; }
            for(auto v:k){ ans.push_back(v); }
        }
        return ans;
    }
};
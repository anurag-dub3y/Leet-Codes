class Solution {
public:
    int ans=0;
    set<vector<int>> s;
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        func(nums,0);
        return ans;
    }
    void func(vector<int>& nums, int ind){
        if(ind>=nums.size()){ 
            // print(nums); 
            if(!s.count(nums)){
                ans++; s.insert(nums); return;
            }
        }
        for(int i=ind; i<nums.size(); i++) {
            if(i>ind && nums[i]==nums[ind]){ continue; }
            swap(nums[i], nums[ind]);
            if((ind==0) || (ind>0 && isSquare(nums[ind]+nums[ind-1]))){
                func(nums,ind+1);
            }
            swap(nums[i], nums[ind]);
        }
    }
    void print(vector<int> &nums){
        for(auto i:nums){ cout<<i<<' '; }
        cout<<endl;
    }
    bool isSquare(int v) {
        int r = sqrt(v);
        return r * r == v;
    }
};
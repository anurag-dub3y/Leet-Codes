class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        int r=1LL<<nums.size();
        for(int i=0; i<r; i++){
            int prev=-1, check=0;
            vector<int> curr;
            cout<<i<<' ';
            for(int j=0; j<nums.size(); j++){
                if(i&(1LL<<j)){
                    if(prev!=-1 and nums[j]<nums[prev]){ check=1; break; }
                    prev=j; curr.push_back(nums[j]);
                }
            }
            if(check==0 and curr.size()>1){ ans.insert(curr); }
        }
        vector<vector<int>> real(ans.begin(),ans.end());
        return real;
    }
};
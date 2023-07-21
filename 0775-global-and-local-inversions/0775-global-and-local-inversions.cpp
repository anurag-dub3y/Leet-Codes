class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // vector<pair<int,int>> vp;
        // int local=0;
        // for(int i=0; i<nums.size(); i++){
        //     vp.push_back({nums[i],i});
        //     if(i>0){ local+=nums[i]<nums[i-1]; }
        // }
        // sort(begin(vp),end(vp));
        // int global=0;
        // for(int i=0; i<vp.size(); i++){
        //     global+=abs(vp[i].second-i);
        // }
        // cout<<global<<' '<<local<<endl;
        // return global==local;
        for(int i = 0; i < size(nums); i++){ if(abs(nums[i] - i) > 1) return false; }
	    return true;
    }
};
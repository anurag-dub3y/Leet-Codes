class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(begin(nums),end(nums),[&](string a, string b){
            if(a.length()!=b.length()){ return a.length()>b.length(); }
            return a>b;
        });
        // for(auto &s:nums){ cout<<s<<' '; } cout<<endl;
        return nums[k-1];
    }
};
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(auto q:queries){
            int len=0, curr=0, i=0, n=nums.size();
            while(i<n){
                curr+=nums[i++];
                if(curr<=q){ len++; }
                else{ break; }
            }
            ans.push_back(len);
        }
        return ans;
    }
};
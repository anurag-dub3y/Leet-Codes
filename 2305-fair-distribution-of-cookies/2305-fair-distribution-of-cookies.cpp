class Solution {
public:
    int n, ans=INT_MAX;
    void backtrack(int i, vector<int>&cookies, vector<int> &nums){
        if(i==n){	
            ans=min(ans,*max_element(nums.begin(),nums.end()));
            return;
            }
	
        for(auto &it:nums){
            it+=cookies[i];
            backtrack(i+1,cookies,nums);
            it-=cookies[i];
        }
                    return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int> nums(k,0);
        backtrack(0,cookies,nums);
        return ans;
    }
};
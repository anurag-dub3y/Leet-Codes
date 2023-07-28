class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<pair<int,int>> vp;
        for(int i=0; i<nums.size(); i++){
            vp.push_back({nums[i],i});
        }
        sort(begin(vp),end(vp));
        int i=1, ans=0, mn=vp[0].first;
        while(i<nums.size()){
            if(vp[i].first<=mn){
                ans+=(mn+1-vp[i].first);
                vp[i].first=mn+1;
            }
            mn=vp[i].first;
            // cout<<mn<<' ';
            i++;
        }
        // cout<<endl;
        return ans;
    }
};
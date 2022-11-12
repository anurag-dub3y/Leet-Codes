class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s(nums.begin(), nums.begin() + k);
        vector<double> ans;
        auto median = next(s.begin(),k/2);
        for(int i=k; ; i++){
            ans.push_back((double(*median) + *prev(median,1-k%2)) / 2);
            if(i==nums.size()){ return ans; }
            s.insert(nums[i]);
            if(nums[i]<*median){ median--; }
            if(nums[i-k]<=*median){ median++; }
             s.erase(s.lower_bound(nums[i-k])); 
        }
        return ans;
    }
};
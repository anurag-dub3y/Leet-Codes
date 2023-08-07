typedef pair<int,int> pii;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        int j=0;
        map<int,int> keys;   
        auto findLower = [&](int x) {
            if(x==keys.begin()->first){ return keys.begin(); }
            auto it = keys.lower_bound(x);
            if (it == keys.begin()) { return keys.end(); }
            return --it;
        };
        auto findHigher = [&](int x) {
            auto it = keys.upper_bound(x);
            return it;
        };
        for(int i=0; i<n; i++){
            if(i-j>indexDiff){ 
                if(keys[nums[j]]==j){
                    keys.erase(nums[j]);
                }
                j++;
            }
            auto l=findLower(nums[i]), r=findHigher(nums[i]);
            if(l!=keys.end() and nums[i]-l->first<=valueDiff){
                return true;
            }
            else if(keys[nums[i]]!=0){
                return true;
            }
            else if(r!=keys.end() and r->first-nums[i]<=valueDiff){
                return true;
            }
            keys[nums[i]]=i;
        }
        return false;
    }
};
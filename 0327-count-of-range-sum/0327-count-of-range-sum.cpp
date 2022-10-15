#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ordered_set OS;         
        ll ans=0, sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            OS.insert({sum,i});
        }
        sum=0;
        for(int i=0; i<nums.size(); i++){
            int x=OS.order_of_key({sum+upper+1,-1000000});
            int y=OS.order_of_key({sum+lower,-1000000});
            ans+=(x-y);
            sum+=nums[i];
            OS.erase({sum,i});
        }
        return ans;
    }
};
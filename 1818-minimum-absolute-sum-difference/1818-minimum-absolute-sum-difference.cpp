typedef long long ll;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<ll> s(begin(nums1),end(nums1));
        ll sum=0, mod=1e9+7, n=nums1.size();
        for(int i=0; i<n; i++){ sum+=abs(nums1[i]-nums2[i]); }
        ll ans=sum;
        for(int i=0; i<nums2.size(); i++){
            auto it=s.lower_bound(nums2[i]);
            if(it==s.end()){
                ll mx=*s.rbegin();
                ans=min(ans,sum+abs(mx-nums2[i])-abs(nums2[i]-nums1[i]));
            }
            else{
                ll mx=*it;
                ans=min(ans,sum+abs(mx-nums2[i])-abs(nums2[i]-nums1[i]));
                if(it!=s.begin()){
                    it=prev(it);
                    mx=*it;
                    ans=min(ans,sum+abs(mx-nums2[i])-abs(nums2[i]-nums1[i]));
                }
            }
        }
        return ans%mod;
    }
};

// 1 4 0
// 1 2 2
#define ll long long
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        auto findMaxIndex=[&](ll  val, ll midval) {
            int l = 0, r = nums2.size()-1 , res= -1;
            while(l<=r) {
                long long mid = (l+r)/2;
                if(val*nums2[mid]<=midval) {
                    res=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            return res+1;
        };
        auto findMinIndex=[&](ll  val, ll midval) {
            int l = 0  , r = nums2.size()-1 , res=  r+1;
            while(l<=r) {
                long long mid = (l+r)/2;
                if(val*nums2[mid]<=midval){
                    res=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            return nums2.size()-res;
        };
        auto find=[&](const ll &mid){
            ll cnt=0;
            for(auto i:nums1){
                if(i==0){
                    if(mid>=0){ cnt+=nums2.size(); }
                }
                else if(i>0){ cnt+=findMaxIndex(i,mid); }
                else{ cnt+=findMinIndex(i,mid); }
            }
            return cnt>=k;
        };
        ll l=-1e10, h=1e10, ans=h+1;
        while(l<=h){
            ll mid=(l+h)/2;
            if(find(mid)){
                h=mid-1;
                ans=mid;
            }
            else{ l=mid+1; }
        }
        return ans;
    }
};
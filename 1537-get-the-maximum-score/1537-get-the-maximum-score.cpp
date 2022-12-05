class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size(), mod=1e9+7;
        vector<long long> sum1(m+1,0), sum2(n+1,0);
        for(int i=0; i<m; i++){
            sum1[i+1]=(sum1[i]+nums1[i]);
        }
        for(int i=0; i<n; i++){
            sum2[i+1]=(sum2[i]+nums2[i]);
        }
        vector<int> ind1, ind2;
        ind1.push_back(0); ind2.push_back(0);
        for(int i=0; i<m; i++){
            if(binary_search(nums2.begin(),nums2.end(),nums1[i])){
                int i2=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
                ind1.push_back(i+1); ind2.push_back(i2+1);
            }
        }
        ind1.push_back(m); ind2.push_back(n);
        long long sum=0, k=ind1.size();
        for(int r=1; r<k; r++){
            long v1=(sum1[ind1[r]]-sum1[ind1[r-1]]);
            long v2=(sum2[ind2[r]]-sum2[ind2[r-1]]);
            sum=(sum+max(v1,v2))%mod;
        }
        return (int)sum%mod;
    }
};
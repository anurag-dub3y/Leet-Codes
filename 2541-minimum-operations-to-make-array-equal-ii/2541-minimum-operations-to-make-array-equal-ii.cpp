class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long add=0, sub=0;
        for(int i=0; i<nums1.size(); i++)
            if(nums1[i]!=nums2[i]){
                if(k==0 or abs(nums1[i]-nums2[i])%k!=0){ return -1; }
                add+=max(0,(nums2[i]-nums1[i])/k);
                sub+=max(0,(nums1[i]-nums2[i])/k);
            }
        return add!=sub?-1:add;
    }
};


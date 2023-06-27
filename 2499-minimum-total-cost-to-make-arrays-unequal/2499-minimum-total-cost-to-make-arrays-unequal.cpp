// class Solution {
// public:
//     long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         map<int,set<int>> mp;
//         for(int i=0; i<n; i++){
//             mp[nums1[i]].insert(i);
//         }
//         long long ans=0;
//         for(int i=0; i<n; i++){
//             if(nums1[i]==nums2[i]){
//                 int mncost=1e6, x;
//                 for(auto it:mp){
//                     if(it.first==nums1[i]){ continue; }
//                     for(auto j:it.second){
//                         if(nums2[j]!=nums1[i]){
//                             if(mncost>i+j){ mncost=i+j; x=j; }
//                         }
//                     }
//                 }
//                 if(mncost==1e6){ return -1; }
//                 cout<<i<<' '<<x<<' ';
//                 cout<<"swapping "<<nums1[i]<<','<<nums1[x]<<'\n';
//                 mp[nums1[x]].erase(x); mp[nums1[i]].erase(i);
//                 mp[nums1[x]].insert(i); mp[nums1[i]].insert(x);
//                 swap(nums1[i],nums1[x]);
//                 ans+=(i+x);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        
        vector<int> counts(100005, 0);
        int dominantCnt = 0;
        int dominantNum = -1;
        int involvedCnt = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                counts[nums1[i]]++;
                if (counts[nums1[i]] > dominantCnt) {
                    dominantCnt = counts[nums1[i]];
                    dominantNum = nums1[i];
                }
                involvedCnt++;
            }
        }
        if (dominantCnt > involvedCnt / 2) {
            for (int i = 0; i < n; ++i) {
                if (nums1[i] != nums2[i] && nums1[i] != dominantNum && nums2[i] != dominantNum) {
                    counts[nums1[i]]++;
                    involvedCnt++;
                    ans += i;
                    if (dominantCnt <= involvedCnt / 2) {
                        return ans;
                    }
                }
            }
            return -1;
        }
        else {
            return ans;
        }
    }
};
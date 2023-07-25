class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
//         sort(begin(nums),end(nums));
//         int sz = nums.size();
//         if (sz % k != 0) return false; // If the array cannot be divided evenly, return false.

//         unordered_map<int, int> map, check;
//         for (int i = 0; i < sz; i++) {
//             map[nums[i]]++;
//         }

//         for (int it = 0; it < sz; it++) {
//             if (map[nums[it]] <= 0){ continue; }
//             if (check[nums[it] - 1] > 0) {
//                 check[nums[it] - 1]--;
//                 map[nums[it]]--;
//                 check[nums[it]]++;
//             } 
//             else {
//                 int current = nums[it];
//                 for (int j = 0; j < k; j++) {
//                     if (map[current + j] > 0) {
//                         map[current + j]--;
//                     } 
//                     else {
//                         return false; // Unable to form a consecutive subsequence of length k.
//                     }
//                     check[current + k - 1]++;
//                 }
//             }
//         }
//         return true;
        map<int,int> mp;
        for(auto &i:nums){ mp[i]++; }
        for(auto &[i,freq]:mp){
            if(freq>0){
                for(int j=i+k-1; j>=i; j--){
                    mp[j]-=freq;
                    if(mp[j]<0){ return false; }
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m1;
        for(auto i:nums1){ m1[i[0]]=i[1]; }
        for(auto &i:nums2){
            if(m1.count(i[0])){ i[1]+=m1[i[0]]; m1.erase(i[0]); }
        }
        for(auto j:m1){
            nums2.push_back({j.first,j.second});
        }
        sort(nums2.begin(),nums2.end());
        return nums2;
    }
};
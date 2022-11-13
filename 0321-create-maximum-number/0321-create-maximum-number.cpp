class Solution {
public:
    // Return lexicrographically largest vector of size k from nums1
    vector<int> nextGreater(vector<int>& nums, int k){
        int drop = nums.size() - k;
        vector<int> out;
        for (int num : nums) {
            while (drop && out.size() && out.back() < num) {
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }
        out.resize(k);
        return out;
    }
    
    // Return lexicrographically largest vector of size req from nums1 and nums2 combination
    vector<int> merge(vector<int>& nums1, vector<int> &nums2){
        vector<int> out;
        auto i1 = nums1.begin(), end1 = nums1.end();
        auto i2 = nums2.begin(), end2 = nums2.end();
        while (i1 != end1 || i2 != end2){
            out.push_back(lexicographical_compare(i1, end1, i2, end2) ? *i2++ : *i1++);
        }
        return out;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k,-1);
        int n1=nums1.size(), n2=nums2.size();
        for(int i=max(k-n2, 0); i<=min(k, n1); i++){
            // if(k-i>nums2.size() or i>nums1.size()){ continue; }
            vector<int> x=nextGreater(nums1,i), y=nextGreater(nums2,k-i);
            vector<int> temp=merge(x,y);
            ans=max(ans,temp);
        }        
        return ans;
    }
};
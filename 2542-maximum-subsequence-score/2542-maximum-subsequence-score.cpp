class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        for(int i=0; i<nums1.size(); i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(rbegin(v),rend(v));
        multiset<int> m;
        long long sum=0LL, ans=0LL;
        for(auto i:v){
            int a=i[0], b=i[1];
            m.insert(b);
            sum+=b;
            if(m.size()>k){ 
                sum-=*m.begin(); m.erase(m.begin()); 
            }
            if(m.size()==k){
                ans=max(ans,sum*a);
            }
        }
        return ans;
    }
};
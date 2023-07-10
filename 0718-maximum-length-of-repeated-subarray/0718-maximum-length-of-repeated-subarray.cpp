class Solution {
public:
    using ull=unsigned long long int; 
    ull P=103LL, m, n;
    vector<ull> p, hsh1, hsh2;
    bool check(int len, vector<int> &nums1, vector<int> &nums2){
        map<ull,vector<int>> seen;
        for(int i=0; i+len<=m; i++){
            ull curr=(hsh1[i+len]-hsh1[i]*p[len]);
            // cout<<curr<<' ';
            seen[curr].push_back(i);
        }
        // cout<<endl;
        for(int i=0; i+len<=n; i++){
            ull curr=(hsh2[i+len]-hsh2[i]*p[len]);
            if(!seen.count(curr)){ continue; }
            for(auto j:seen[curr]){
                if(equal(nums1.begin()+j, nums1.begin()+j+len, nums2.begin()+i, nums2.begin()+i+len)){
                    return true;
                }
            }
        }
        // cout<<endl;
        return false;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();
        hsh1.assign(m+1, 0); 
        hsh2.assign(n+1, 0); 
        p.assign(max(m, n) + 1, 1);
        for(int i = 0; i < max(m, n); ++i){ p[i+1] = (p[i] * P); }
        for(int i = 0; i < m; ++i){ hsh1[i+1] = (hsh1[i] * P + nums1[i]); } 
        for(int i = 0; i < n; ++i){ hsh2[i+1] = (hsh2[i] * P + nums2[i]); } 
        int low=1, high=min(m,n), ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,nums1,nums2)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    
};
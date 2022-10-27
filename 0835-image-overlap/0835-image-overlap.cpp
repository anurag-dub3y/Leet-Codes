class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<int> v1, v2;
        for(int i=0; i<n*n; i++){ if(img1[i/n][i%n]==1){ v1.push_back((i/n)*100+i); } }
        for(int i=0; i<n*n; i++){ if(img2[i/n][i%n]==1){ v2.push_back((i/n)*100+i); } }
        int ans=0;
        unordered_map<int,int> u;
        for(auto i:v1){
            for(auto j:v2){
                u[i-j]++;
                ans=max(ans,u[i-j]);
            }
        }
        return ans;
    }
};
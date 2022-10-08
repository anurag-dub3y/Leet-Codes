class Solution {
public:
    int m,n; 
    int kthSmallest(vector<vector<int>>& mat, int k) {
        m=mat.size(), n=mat[0].size();
        int l=mat[0][0], r=mat[m-1][n-1], ans;
         while(l<=r) {
            int mid=(l+r)>>1;
            if(elementsLessThanOrEqualToX(mat, mid)>=k) {
                ans=mid; r=mid-1;
            } 
            else l=mid+1; 
        }
        return ans;
    }
    int elementsLessThanOrEqualToX(vector<vector<int>>& mat, int x){
        int cnt=0, j=n-1;
        for(int i=0; i<m; i++) {
            while(j>=0 && mat[i][j]>x){ j--; }
            cnt+=(j+1);
        }
        return cnt;
    }
};
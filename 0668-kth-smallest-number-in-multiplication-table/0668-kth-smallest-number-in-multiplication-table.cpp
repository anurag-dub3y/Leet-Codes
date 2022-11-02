class Solution {
public:
    int count(int m, int n, int num){
        int ans=0;
        for(int i=1; i<=m; i++){
            ans+=min(num/i,n);
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n, mid, ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(count(m,n,mid)<k){ l=mid+1; }
            else{ r=mid-1; ans=mid; }        
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int mxLen=0, i=0, j=0, n=nums.size(), curr=0, sum=accumulate(begin(nums),end(nums),0);
        if(sum==x){ return n; }
        while(i<n){
            curr+=nums[i];
            while(curr>sum-x and j<=i){ curr-=nums[j++]; }
            // cout<<curr<<' '<<i<<'-'<<j<<endl;
            if(curr==sum-x){
                mxLen=max(mxLen,i-j+1);
            }
            i++;
        }
        return mxLen==0?-1:n-mxLen;
    }
};
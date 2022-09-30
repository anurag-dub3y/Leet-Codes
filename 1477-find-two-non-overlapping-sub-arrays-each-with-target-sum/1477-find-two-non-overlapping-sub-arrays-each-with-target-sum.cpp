class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> prefix(n), suffix(n);
        int j=-1, sum=0, minLen=1e9;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            while(sum>target && j<=i){
                sum-=arr[++j];
            }
            if(sum==target){ minLen=min(minLen,i-j); }
            prefix[i]=(minLen==1e9)?-1:minLen;                                                               
        }            
        j=n, minLen=1e9, sum=0;
        for(int i=n-1; i>=0; i--){
            sum+=arr[i];
            while(sum>target && i<=j){
                sum-=arr[--j];
            }
            if(sum==target){
                minLen=min(minLen,j-i);
            }
            suffix[i]=(minLen==1e9)?-1:minLen;
        }
        int ans=1e9;
        for(int i=0; i<n; i++){
            int left=prefix[i];
            int right = (i+1>=n ? -1 : suffix[i+1]);
            if(left!=-1 && right !=-1) ans = min(ans, left+right);
        }
        return ans==1e9?-1:ans;
    }
};
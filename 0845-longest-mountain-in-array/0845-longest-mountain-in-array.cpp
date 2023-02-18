class Solution {
public:
    vector<int> fLen(vector<int>& arr, int n){
        vector<int> f(n,0);
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){ f[i]=f[i-1]+1; }
        }
        return f;
    }
    vector<int> bLen(vector<int>& arr, int n){
        vector<int> f(n,0);
        for(int i=n-2; i>=0; i--){
            if(arr[i]>arr[i+1]){ f[i]=f[i+1]+1; }
        }
        return f;
    }
    int longestMountain(vector<int>& arr) {
        int n=arr.size(), ans=0;
        vector<int> f=fLen(arr,n), b=bLen(arr,n);
        for(int i=0; i<n; i++){
            if(f[i]!=0 and b[i]!=0){
                ans=max(ans,f[i]+b[i]);
            }
        }
        return ans==0?0:1+ans;
    }
};
class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n), right(n);
        stack<int> lefts, rights;
        lefts.push(0); rights.push(n-1);
        left[0]=1; right[n-1]=1;
        for(int i=0; i<n; i++){
            while(!lefts.empty() && arr[lefts.top()]>=arr[i]){ lefts.pop(); }
            if(lefts.empty()){ left[i]=i+1; }
            else{ left[i]=i-lefts.top(); }
            lefts.push(i);
        }
        for(int i=n-2; i>=0; i--){
            while(!rights.empty() && arr[rights.top()]>arr[i]){ rights.pop(); }
            if(rights.empty()){ right[i]=n-i; }
            else{ right[i]=rights.top()-i; }
            rights.push(i);
        }
        cout<<endl;
        int ans=0;
        for(int i=0; i<n; i++){
            // cout<<arr[i]<<' '<<left[i]<<' '<<right[i]<<endl;
            long long prod=(left[i]*right[i])%mod;
            prod=(prod*arr[i])%mod;
            ans=(ans+prod)%mod;
        }
        return ans%mod;
    }
};
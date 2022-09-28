class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n=a.size();
        vector<int> left(n,1), right(n,1);
        for(int i=1; i<n; i++){
            if(a[i]<=a[i-1]){ left[i]=1+left[i-1]; }
        }
        for(int i=n-2; i>=0; i--){
            if(a[i]<=a[i+1]){ right[i]=1+right[i+1]; }
        }
        vector<int> ans;
        for(int i=1; i<n-1; i++){
            // cout<<left[i-1]<<' '<<right[i+1]<<endl;
            if(left[i-1]>=k && right[i+1]>=k){ ans.push_back(i); }
        }
        return ans;
    }
};
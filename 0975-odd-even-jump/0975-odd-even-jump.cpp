class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size(), ans=1;
        vector<int> odd(n,0), even(n,0);
        odd[n-1]=1; even[n-1]=1;
        map<int,int> m;
        m[arr[n-1]]=n-1;
        for(int i=n-2; i>=0; i--){
            auto lb=m.lower_bound(arr[i]), ub=m.upper_bound(arr[i]);
            if(lb!=m.end()){
                odd[i]=even[lb->second];
            }
            if(ub!=m.begin()){
                ub--;
                even[i]=odd[ub->second];
            }
            if(odd[i]){ ans++; }
            m[arr[i]]=i;
        }
        return ans;
    }
};
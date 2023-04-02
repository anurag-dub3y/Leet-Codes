class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n=arr.size();
        long long ans=0LL;
        for(int i=0; i<k; i++){
            vector<int> subs;
            for(int j = i; arr[j] != 0; j = (j + k) % n){
                subs.push_back(arr[j]);
                arr[j]=0;
            }
            if(subs.empty()){ continue; }
            sort(begin(subs),end(subs));
            int med=subs[subs.size()/2];
            for(auto x:subs){ ans+=abs(x-med); }
        }
        return ans;
    }
};
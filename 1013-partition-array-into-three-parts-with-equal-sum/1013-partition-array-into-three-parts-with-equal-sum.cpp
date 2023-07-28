class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=accumulate(begin(arr),end(arr),0);
        if(sum%3!=0){ return false; }
        int cnt=0, curr=0;
        for(int i=0; i<arr.size(); i++){
            curr+=arr[i];
            if(curr==sum/3){ curr=0; cnt++; }
        }
        return cnt>=3;
    }
};
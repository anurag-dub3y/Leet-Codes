class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(begin(arr),end(arr));
        int n=size(arr), ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int a=arr[i], b=arr[j], currLen=2;
                while(s.count(a+b)){
                    int k=b;
                    b=a+b; a=k; currLen++;
                }
                ans=max(ans,currLen);
            }
        }
        return ans>2?ans:0;
    }
};
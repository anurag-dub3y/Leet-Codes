class Solution {
public:
    int kConcatenationMaxSum(vector<int> &A, int k) {
       int result = A[0], curSum = A[0], n = A.size();
       int N = n * min(2,k); 
       long sum = accumulate(A.begin(),A.end(),0l);
       for(int i=1; i<N; i++){
           curSum = max(A[i%n], A[i%n] + curSum);
           result = max(result,curSum);
       }
       if(sum<0 || k==1 || result<0){ return max(0,result); }
       return (result + (k-2) * sum)%1000000007;
   }
};
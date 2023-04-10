set<int> primes;
class Solution {
public:
    vector<int> p;
    void sieve(){
        p.assign(10000005, 1);
        p[0] = p[1] = 0;
        for(int i=2;i*i<10000005;i++){
           if(p[i] == 0) continue;
           for(int j=i*i;j<10000005;j+=i){
               p[j] = 0;
           }
        }
        for(int i=2;i<10000005;i++){
           if(p[i]){
               primes.insert(i);
           }
        }
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        if(primes.empty()){ sieve(); }
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(primes.count(nums[i][i])){ ans=max(ans,nums[i][i]); }
            if(primes.count(nums[i][n-i-1])){ ans=max(ans,nums[i][n-i-1]); }
        }
        return ans;
    }
};
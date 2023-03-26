class Solution {
public:
    vector<int> sieve(int n){
        vector<bool> p(n+1,true);
        vector<int> primes;
        p[0] = p[1] = 0;
        for(int i=2; i*i<=n; i++){
           if(p[i] == 0){ continue; }
           for(int j=i*i; j<=n; j+=i){
               p[j] = 0;
           }
        }
        for(int i=2; i<n; i++){
           if(p[i]){ primes.push_back(i); }
        }
        return primes;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){ continue; }
            vector<int> primes=sieve(nums[i]);
            for(int j=0; j<primes.size(); j++){
                if(nums[i]-primes[j]<nums[i+1]){
                    nums[i]-=primes[j]; break;
                }
            }
        }
        for(int i=0; i<n-1; i++){
            if(nums[i]>=nums[i+1]){ return false; }
        }
        return true;
    }
};
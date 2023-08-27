class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> p(41);
        for(auto c:nums){
            for(int j=0;j<31;j++){
                if(c>>j&1){ p[j]++; }
            }
        }
        int ops=0;
        for(int i=0;i<31;i++){
            if(target>>i&1){
                if(p[i]){ p[i]--; }
                else {
                    for(int j=i+1;j<31;j++){
                        if(p[j]){
                            p[j]--;
                            for(int k=i;k<j;k++){ p[k]++; ops++; }
                            p[i]++;
                            break;
                        }
                    }
                    if(!p[i]){ return -1; }
                    p[i]--;
                }
            }
            p[i+1]+=p[i]/2;            
        }
        return ops;
    }
};

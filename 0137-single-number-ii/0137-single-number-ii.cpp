class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32];
        memset(bits,0,sizeof(bits));
        for(int b=0; b<32; b++){
            int mask=1<<b;
            for(auto i:nums){
                if((i&mask)!=0){ bits[b]++; }
            }
        }
        int ans=0;
        for(int b=0; b<32; b++){
            if(bits[b]%3==1){
                ans|=1<<b;
            }
        }
        return ans;
    }
};
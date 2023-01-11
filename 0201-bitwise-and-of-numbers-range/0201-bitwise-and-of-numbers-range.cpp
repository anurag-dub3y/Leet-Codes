class Solution {
public:
    int msbPos(int n){
        int msb_p = -1;
        while(n){
            n = n>>1;
            msb_p++;
        }
        return msb_p;
    }
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        while(left and right){
            int a=msbPos(left), b=msbPos(right);
            if(a!=b){ break; }
            ans+=(1<<a);
            left-=(1<<a); right-=(1<<b);
        }
        return ans;
    }
};
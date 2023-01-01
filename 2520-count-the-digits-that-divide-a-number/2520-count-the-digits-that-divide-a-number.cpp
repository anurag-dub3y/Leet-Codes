class Solution {
public:
    int countDigits(int num) {
        int f[10]={0};
        int x=num;
        while(x){ ++f[x%10]; x/=10; }
        int ans=0;
        for(int i=0; i<10; i++){
            if(f[i]!=0 and num%i==0){ ans+=f[i]; }
        }
        return ans;
    }
};
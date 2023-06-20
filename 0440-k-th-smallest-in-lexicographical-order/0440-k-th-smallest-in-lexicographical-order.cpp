// https://www.youtube.com/watch?v=355Cq7Stuv4
class Solution {
public:
    int findNums(int n, long long prefix){
        long long f=1, cnt=0;
        for(int d=1; d<=9; d++){
            long long mn=prefix*f, mx=prefix*f+f-1;
            if(n<mn){ break; }
            else if(n>=mn and n<=mx){
                cnt+=(n-mn+1); break;
            }
            else{ cnt+=f; }
            f*=10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k, int pref=0) {
        if(k>0){
            for(int i=(pref==0)?1:0; i<=9; i++){
                long long x=pref*10+i;
                int prefixCount=findNums(n,x);
                if(k<=prefixCount){ return findKthNumber(n,k-1,x); }
                k-=prefixCount;
            }
        }
        return pref;
    }
};
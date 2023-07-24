// int mod=1e9+7, flag=0;
// long long fact[10004];
// bool prime[10001];
// vector<int> primes;
// unordered_map<int,unordered_map<int,int>> factors;
// long long binpowmod(long long a, long long b, long long d){
//     long long result=1;
//     long long base=a;
//     while(b) {
//         if(b&1){ result=(result*base)%d; }
//         b>>=1;
//         base=(base*base)%d;
//     }
//     return result;
// }
// long long modinv(long long a) {
//     return binpowmod(a,mod-2,mod);
// }
// void _init(){
//     fact[0]=1;
//     for(int i=1; i<=10000; i++){
//         fact[i]=(1LL*i*fact[i-1])%mod;
//     }
//     memset(prime,true,sizeof(prime));
//     prime[0]=false;
//     prime[1]=false;
//     for(int i=2; i<=10000; i++){
//         if(prime[i]){
//             for(int j=i*i; j<=10000; j+=i){ prime[j]=0; }
//             primes.push_back(i);
//         }    
//     }
//     for(int i=2; i<=10000; i++){
//         int val=i;
//         for(int j=0; j<primes.size() and val>1; j++){
//             while(val%primes[j]==0){
//                 factors[i][primes[j]]++;
//                 val/=primes[j];
//             }
//         }
//     }
// }
// class Solution {
// public:
//     vector<int> waysToFillArray(vector<vector<int>>& queries) {
//         if(flag==0){ _init(); flag=1; }
//         vector<int> ans(queries.size(),1);
//         for(int i=0; i<queries.size(); i++){
//             for(auto it=factors[queries[i][1]].begin(); it!=factors[queries[i][1]].end(); it++){
//                 long long v1=modinv(it->second), v2=modinv(queries[i][0]-1);
//                 long long v3=(1LL*v1*v2)%mod;
//                 long long mult=(1LL*ans[i]*fact[queries[i][0]+it->second-1])%mod;
//                 ans[i]=(1LL*mult*v3)%mod;
//             }            
//         }
//         return ans;
//     }
// };

bool flag=false; //used to calculate only once
bool prime[10001]; //calculate once
long factorial[20001]; //calculate once
long d=1000000007;
vector<int> overall;
unordered_map<int,unordered_map<int,int>> total; //calculate once
long powmod(long a,long b,long d)
{
    //(a^b)%d
    long result=1;
    long base=a;
    while(b)
    {
        if(b&1) result=(result*base)%d;
        b>>=1;
        base=(base*base)%d;
    }
    return result;
}
long modinv(long a,long d)
{
    //(a^-1)%d
    return powmod(a,d-2,d);
}
class Solution 
{
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) 
    {
        if(!flag)
        {
            //Note: calculate only for once within this scope
            //use sieve to get primes for later prime factorization
            memset(prime,true,sizeof(prime));
            prime[0]=false;
            prime[1]=false;
            for(int i=2;i<=10000;i++)
            {
                if(prime[i])
                {
                    for(int j=i*i;j<=10000;j+=i) prime[j]=false;

                    overall.push_back(i);
                }
            }
            //prime factoization for all number from 2~10000
            //eg. if 12=2*2*3, then total[12][2]=2,total[12][3]=1
            for(int i=2;i<=10000;i++)
            {
                int current=i;
                for(int j=0;j<overall.size()&&current>1;j++)
                {
                    while(current%overall[j]==0)
                    {
                        total[i][overall[j]]++;
                        current/=overall[j];
                    }
                }
            }
            //pre-calculate factorial for later combination for once
            factorial[0]=1;
            for(int i=1;i<=20000;i++) factorial[i]=(factorial[i-1]*i)%d;
            flag=true;
        }
        int n=queries.size();
        vector<int> result(n,1);
        long d=1000000007;
        for(int i=0;i<n;i++)
        {
            for(unordered_map<int,int>::iterator it=total[queries[i][1]].begin();it!=total[queries[i][1]].end();it++)
            {
                result[i]=(result[i]*factorial[queries[i][0]+it->second-1]%d*modinv(factorial[queries[i][0]-1],d)%d*modinv(factorial[it->second],d)%d);
            }
        }
        return result;
    }
};

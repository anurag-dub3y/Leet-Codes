// vector<int> primes;
// bool flag=false;
// void _init(){
//     flag=true;
//     const int N=1e5+5;
//     bool p[N]={0};
//     for(int i=2; i*i<=N; i++){
//         if(p[i]==1){ continue; }
//         primes.push_back(i);
//         for(int j=1; i*j<N; j++){ p[i*j]=1; }
//     }
// }
class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int scores(int n)
        {
            if(n==1)
            {
                return 0;
            }
            int num = 0;
            if (n % 2 == 0)
            {
                num++;

                while (n % 2 == 0)
                {
                    n /= 2;
                }
            }

            for (int i = 3; i*i <=n; i += 2)
            {
                if (n % i == 0)
                {
                    num++;

                    while (n % i == 0)
                    {
                        n /= i;
                    }
                }
            }

            if (n > 2)
                num++;
            return num;
       }
    int maximumScore(vector<int>& nums, int k) {
        // if(!flag){ _init(); }
        int n=nums.size();
        vector<int> score(n), length(n);
        vector<int> left(n,-1), right(n,n);
        for(int i=0; i<n; i++){ score[i]=scores(nums[i]); }
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() and score[i]>score[st.top()]){ st.pop(); }
            if(!st.empty()){ left[i]=st.top(); }
            st.push(i);
        }
        while(!st.empty()){ st.pop(); }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and score[i]>=score[st.top()]){ st.pop(); }
            if(!st.empty()){ right[i]=st.top(); }
            st.push(i);
        }
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++){
            vp.push_back({nums[i],(i-left[i])*(right[i]-i)});
        }
        sort(rbegin(vp),rend(vp));
        long long ans=1LL, mod=1e9+7, i=0;
        while(k>0){
            auto &[val,len]=vp[i];
            // cout<<val<<' '<<len<<endl;
            long long f=binpow(val,min(len,k),mod);
            ans=(ans*f)%mod; 
            k-=len;
            i++;
        }
        return ans;
    }
};
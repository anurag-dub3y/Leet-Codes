//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
typedef long long int ll;
ll bit[500005]={0}, N=5e5+2;
ll sum(int i){
    ll ans=0;
    while(i>0){
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}
void update(int i, int val){
    while(i<N){
        bit[i]+=val;
        i+=(i&-i);
    }
}
long long int inversionCount(long long arr[], long long n){
    map<ll,ll> m;
    for(int i=0; i<n; i++){
        m[arr[i]]=0;
    }
    ll cnt=1;
    for(auto &it:m){
        it.second=cnt++;
    }
    for(int i = 0; i < n; ++i){
		arr[i]=m[arr[i]];
	}
    ll ans=0;
    for(int i=0; i<n; i++){
        update(arr[i],1LL);
        ans+=sum(N)-sum(arr[i]);
    }
    return ans;
}

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
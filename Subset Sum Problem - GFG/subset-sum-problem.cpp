//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

int dp[100005][101];
class Solution{   
public:
    bool find(int i, int sum, vector<int> &arr){
        if(sum<0){ return false; }
        if(sum==0){ return true; }
        if(i==arr.size()){ return false; }
        if(dp[sum][i]!=-1){ return dp[sum][i]; }
        return dp[sum][i]=find(i+1,sum-arr[i],arr) | find(i+1,sum,arr);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        memset(dp,-1,sizeof(dp));
        return find(0,sum,arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
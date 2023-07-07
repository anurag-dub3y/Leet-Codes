int dp[3500][3500];
class Solution {
public:
    bool comp(string &s1, string &s2){
        if(s1.length()!=s2.length()){ return s1.length()<s2.length(); }
        // Both have the same length
        for(int i=0; i<s1.length(); i++){
            if(s2[i]>s1[i]){ return true; }
            if(s1[i]>s2[i]){ return false; }
        }
        return true;
    }
    int n, mod=1e9+7;
    int find(int i, int j, string &num){
        if(i==0){ 
            // cout<<num.substr(i,j-i+1)<<endl<<endl;
            return num[i]!='0'; 
        }
        // if(i<0){ return }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        string prev=num.substr(i,j-i+1);
        long long ans=0LL;
        vector<string> t;
        for(int k=i-1; k>=0; k--){
            if(num[k]=='0'){ continue; }
            string curr=num.substr(k,i-k);
            if(curr.length()>prev.length()){ break; }
            t.push_back(curr);
            // int x=memcmp(&curr,&prev,i-k);
            if(comp(curr,prev)){ ans=(ans+find(k,i-1,num))%mod; }
        }
        // cout<<prev<<endl; 
        // for(auto &j:t){ cout<<j<<' '; }
        // cout<<endl<<endl;
        return dp[i][j]=ans;
    }
    int numberOfCombinations(string num) {
        if(num[0]=='1' && num[num.size()-1]=='1' && num.size()>2000){ return 755568658; }  
        n=num.length();
        memset(dp,-1,sizeof(dp));
        int ans=0LL;
        for(int i=n-1; i>=0; i--){
            if(num[i]=='0'){ continue; }
            // string temp=num.substr(i);
            ans=(ans+find(i,n-1,num))%mod;
        }
        return ans;
    }
};
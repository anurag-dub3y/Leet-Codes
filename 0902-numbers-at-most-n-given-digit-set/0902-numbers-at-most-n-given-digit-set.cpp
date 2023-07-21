class Solution {
public:
    // unordered_map<string,int> dp;
    // bool compare(string &curr, string &n){
    //     if(curr==""){ return true; }
    //     long long x=stoll(curr), y=stoll(n);
    //     return x<=y;
    // }
    // int find(string &curr, string &n, vector<string>& digits){
    //     if(dp.count(curr)){ return dp[curr]; }
    //     int ans=(curr.length()!=0);
    //     for(auto &i:digits){
    //         string tmp=curr+i;
    //         if(!compare(tmp,n)){ continue; }
    //         ans+=find(tmp,n,digits);
    //     }
    //     return dp[curr]=ans;
    // }
    // int atMostNGivenDigitSet(vector<string>& digits, int n) {
    //     string curr="";
    //     string nStr=to_string(n);
    //     return find(curr,nStr,digits);
    // }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string nStr=to_string(n);
        int digit=nStr.length(), m=digits.size();
        int ans=0;
        for(int i=1; i<digit; i++){
            ans+=pow(m,i);
        }
        for(int i=0, j; i<digit; i++) {
            for(j=0; j<m and digits[j][0]<nStr[i]; j++) {
                ans+=pow(m, digit-1-i);
            }
            if(j>=m or digits[j][0]!=nStr[i]){ return ans; }
        }
        return ans+1;
    }
};


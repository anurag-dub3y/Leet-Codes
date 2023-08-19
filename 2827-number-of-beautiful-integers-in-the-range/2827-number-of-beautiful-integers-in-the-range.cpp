class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string num1=to_string(low), num2=to_string(high);
        return findVals(num1,num2,k);
    }
private:
    int dp[11][2][2][10][10][21][2];
    int leadingZeroes;
    int find(int i, bool tight1, bool tight2, int even, int odd, int rem, bool padded, int k, string &num1, string &num2){
        if(i==num1.length()){ return even==odd and rem==0; }
        int &ans=dp[i][tight1][tight2][even][odd][rem][padded];
        if(ans!=-1){ return ans; }
        int lo = tight1 ? num1[i] - '0' : 0;
        int hi = tight2 ? num2[i] - '0' : 9;
        int count = 0;
        for (int idx = lo; idx <= hi; idx++) {
            if(!padded and idx==0){
                count += find(i+1, tight1 && (idx==lo), tight2 && (idx==hi), even, odd, rem%k, 0, k, num1, num2);
            }
            else{
                count += find(i+1, tight1 && (idx==lo), tight2 && (idx==hi), even+(idx%2==0), odd+(idx%2==1), (10*rem+idx)%k, 1, k, num1, num2);
            }
        }
        return ans=count;
    }
    int findVals(string &num1, string &num2, int k){
        leadingZeroes = num2.length() - num1.length();
        string num1extended = string(leadingZeroes,'0')+num1;
        // cout<<num1extended<<' '<<num2<<endl;
        memset(dp,-1,sizeof(dp));
        return find(0,1,1,0,0,0,0,k,num1extended,num2);
    }
};
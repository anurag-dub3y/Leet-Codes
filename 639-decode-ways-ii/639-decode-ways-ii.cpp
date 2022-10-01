class Solution {
public:
    int numDecodings(string s) {
        vector<long> dp(s.length()+1,0);
        dp[0] = 1;
        if(s[0] == '0'){
            return 0;
        }
        dp[1] = (s[0] == '*') ? 9 : 1;

        for(int i = 2; i <= s.length(); i++){
            char first = s[i-2];
            char second = s[i-1];

            // For dp[i-1]
            if(second == '*'){
                dp[i] += 9*dp[i-1];
            }else if(second > '0'){
                dp[i] += dp[i-1];
            }
            
            // For dp[i-2]
            if(first == '*'){
                if(second == '*'){
                    dp[i] += 15*dp[i-2];
                }else if(second <= '6'){
                    dp[i] += 2*dp[i-2];
                }else{
                    dp[i] += dp[i-2];
                }
            }else if(first == '1' || first == '2'){
                if(second == '*'){
                    if(first == '1'){
                       dp[i] += 9*dp[i-2]; 
                    }else{ // first == '2'
                       dp[i] += 6*dp[i-2]; 
                    }
                }else if( ((first-'0')*10 + (second-'0')) <= 26 ){
                    dp[i] += dp[i-2];    
                }
            }

            dp[i] %= 1000000007;
        }
        /* Return */
        return dp[s.length()];
    }
};
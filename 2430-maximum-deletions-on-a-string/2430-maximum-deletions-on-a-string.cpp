class Solution {
private:
        vector<int> dp;  // memo for recursion, dp[i] is the answer if we started at index i.
        int n;           // size of input
public:
        int find(string_view sv, int pos=0) {
            if (dp[pos]>0) return dp[pos];                  // memoized already
            int ans=1;                                      // there's at least one way always!
            for (int i=1; i<=(n-pos)/2; i++) {
                if (sv.substr(pos,i)==sv.substr(pos+i,i))   // we can delete the first i characters so
                    ans=max(ans, 1+find(sv, pos+i));        // recurse from pos+i position
            }
            dp[pos]=ans;                                    // memoize the answer
            return ans;
        } 
    
        void optimize_tail(const string& s) {         // if the string ends in a tail of same char
            int k=n-1;                         // we can precompute the answers for those positions
            while (k>0 && s[k]==s[k-1]) --k;
            for (int i=k+1; i<n; i++) dp[i]=n-i;
        }
        
        int deleteString(string s) {    
            n=s.size();
            dp.resize(n+1);
            optimize_tail(s);                
            string_view sv ({s.c_str(), s.size()});  // for O(1) substring view
            return find(sv, 0);
        }
    };
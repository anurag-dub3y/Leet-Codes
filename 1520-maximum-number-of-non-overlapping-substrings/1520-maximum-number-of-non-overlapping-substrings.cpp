class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;
        int n=s.length();
        vector<int> l(26,INT_MAX), r(26,INT_MIN);
        for(int i=0; i<n; i++){
            l[s[i]-'a']=min(i,l[s[i]-'a']);
            r[s[i]-'a']=max(i,r[s[i]-'a']);
        }
        // Check the max index I have to consider if I take i in the ans
        auto check=[&](int i){
            int right=r[s[i]-'a'];
            for(int j=i; j<=right; j++){
                if(l[s[j]-'a']<i){ return -1; }
                right=max(right,r[s[j]-'a']);
            }
            return right;
        };
        int prev=-1;
        for(int i=0; i<n; i++){
            if(i==l[s[i]-'a']){
                int mxRight=check(i);
                if(mxRight!=-1){
                    if(i>prev) ans.push_back(s.substr(i,mxRight-i+1));
                    else ans.back()=s.substr(i,mxRight-i+1);
                    prev=mxRight;
                    // cout<<ans.back()<<endl;
                }
            }    
        }
        return ans;
    }
};
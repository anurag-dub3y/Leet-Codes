class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){ st.push(i); }
            else{
                if(st.empty()){ st.push(i); }
                else{
                    if(s[st.top()]=='('){ st.pop(); }
                    else{ st.push(i); }
                }
            }
        }
        int end=n, start=0, ans=0;
        if(st.empty()){ return n; }
        while(!st.empty()){
            int r=st.top(); st.pop();
            ans=max(ans,end-r-1);
            end=r;
        }
        ans=max(ans,end);
        return ans;
    }
};
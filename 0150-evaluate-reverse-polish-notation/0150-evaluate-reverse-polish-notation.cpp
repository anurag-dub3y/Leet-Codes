class Solution {
public:
    bool isChar(string s){
        return s=="+" or s=="-" or s=="*" or s=="/";
    }
    void operate(stack<string> &st, string op){
        long long b=stoll(st.top()); st.pop();
        long long a=stoll(st.top()); st.pop();
        // cout<<a<<' '<<b<<' '<<op<<endl;
        if(op=="+"){ st.push(to_string(a+b)); }
        if(op=="-"){ st.push(to_string(a-b)); }
        if(op=="*"){ st.push(to_string(1LL*a*b)); }
        if(op=="/"){ st.push(to_string(a/b)); }
        return;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        // s.push(tokens[0]);
        for(int i=0; i<tokens.size(); i++){
            if(!isChar(tokens[i])){ s.push(tokens[i]); }
            else{ operate(s,tokens[i]); }
        }
        return stoi(s.top());
    }
};
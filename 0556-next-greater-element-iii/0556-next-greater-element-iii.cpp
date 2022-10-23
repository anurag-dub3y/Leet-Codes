class Solution {
public:
    int nextGreaterElement(int n){
        string toNum=to_string(n);
        string rev=toNum;
        sort(rev.begin(),rev.end());
        reverse(rev.begin(),rev.end());
        if(rev==toNum){ return -1; }
        vector<int> dig;
        while(n){ dig.push_back(n%10); n/=10; }
        reverse(dig.begin(),dig.end());
        stack<int> s;
        for(int i=dig.size()-1; i>=0; i--){
            if(s.empty() or dig[i]>=dig[s.top()]){ s.push(i); }
            else{
                int ind;
                while(!s.empty() && dig[i]<dig[s.top()]){
                    ind=s.top(); s.pop();
                }
                swap(dig[i],dig[ind]);
                sort(dig.begin()+i+1, dig.end());
                break;
            }
        }
        long ans=0;
        for(auto i:dig){ ans*=10; ans+=i; }
        return (ans>INT_MAX or ans<=n)?-1:ans;
    }
};


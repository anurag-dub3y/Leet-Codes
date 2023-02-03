class Solution {
public:
    string convert(string str, int n) {
        vector<string> s(n,"");
        int x=0, flag=1;
        for(int i=0; i<str.length(); i++){
            int z=x%n;
            if(flag==1){
                if(x==n-1){ flag=-1; x--; }
                else{ x++; }
            }
            else if(flag==-1){
                if(x==0){ flag=1; x++; }
                else{ x--; }
            }
            // cout<<z<<" "<<str[i]<<endl; 
            s[z]+=str[i];
        }
        string ans="";
        for(auto i:s){ ans+=i; }
        return ans;
    }
};
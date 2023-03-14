class Solution {
public:
    int intS(string &ex){
        int ans=0;
        for(auto i:ex){ ans*=10; ans+=(i-'0'); }
        return ans;
    }
    vector<int> diffWaysToCompute(string ex) {
        vector<int> ans;
        for(int i=0; i<ex.length(); i++){
            char c=ex[i];
            if(c=='+' or c=='-' or c=='*'){
                vector<int> v1=diffWaysToCompute(ex.substr(0,i));
                vector<int> v2=diffWaysToCompute(ex.substr(i+1));
                for(auto &x:v1){
                    for(auto &y:v2){
                        if(c=='+'){ ans.push_back(x+y); }
                        else if(c=='-'){ ans.push_back(x-y); }
                        else{ ans.push_back(x*y); }
                    }
                }
            }
        }
        if(ans.empty()){
            int num=intS(ex);
            ans.push_back(num);
        }
        return ans;
    }
};
class Solution {
public:
    string pushDominoes(string dom) {
        int n=dom.size();
        vector<int> right(n,0), left(n,0);
        for(int i=0; i<n; i++){
            if(dom[i]=='R'){
                right[i]=1;
            }
            else if(i>0 && dom[i]=='.' && right[i-1]!=0){ right[i]=1+right[i-1]; }
        }
        for(int i=n-1; i>=0; i--){
            if(dom[i]=='L'){
                left[i]=1;
            }
            else if(i<n-1 && dom[i]=='.' && left[i+1]!=0){ left[i]=1+left[i+1]; }
        }
        string ans="";
        for(int i=0; i<n; i++){
            if(right[i]==left[i]){ ans+='.'; }
            else if(right[i]==0 && left[i]){ ans+='L'; }
            else if(left[i]==0 && right[i]){ ans+='R'; }
            else{
                ans+=(min(left[i],right[i])==left[i])?'L':'R';
            }
        }
        return ans;
    }
};
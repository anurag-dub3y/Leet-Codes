class Solution {
public:
    int bestClosingTime(string &c) {
        int Y=count(begin(c),end(c),'Y'), N=count(begin(c),end(c),'N');
        int currPenalty=Y, ind=0, ans=1e9;
        for(int i=0; i<c.length(); i++){
            if(currPenalty<ans){
                ans=currPenalty;
                ind=i;
            }
            if(c[i]=='Y'){ currPenalty--; }
            else if(c[i]=='N'){ currPenalty++; }
        }
        if(currPenalty<ans){ return c.length(); }
        return ind;
    }
};
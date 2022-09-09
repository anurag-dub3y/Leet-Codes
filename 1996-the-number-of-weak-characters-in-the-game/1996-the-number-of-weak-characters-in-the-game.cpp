class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]<b[0]){ return true; }
        else if(b[0]<a[0]){ return false; }
        return a[1]>b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(begin(p),end(p),comp);
        int ans=0, x=INT_MIN;
        for(int i=p.size()-1; i>=0; i--){
            if(x>p[i][1]){ ans++; }
            x=max(x,p[i][1]);
        }
        return ans;
    }
};


class Solution {
public:
    map<pair<int,int>,int> m;
    int dfs(int i, int prev, vector<int> &x, vector<int> &y){
        if(i==x.size()){ return 0; }
        if(m[{i,prev}]){ return m[{i,prev}]; }
        int nxt=upper_bound(begin(y),end(y),prev)-begin(y);
        int ans=2002;
        if(x[i]>prev){ 
            ans=min(ans,dfs(i+1,x[i],x,y)); 
        }
        if(nxt<y.size()){
            ans=min(ans,1+dfs(i+1,y[nxt],x,y));
        }
        return m[{i,prev}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        int ans=dfs(0,-1,arr1,arr2);
        return ans>2001?-1:ans;
    }
};
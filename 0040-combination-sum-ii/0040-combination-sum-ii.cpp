class Solution {
public:
    void dfs(vector<vector<int>>& res, int order, int target, vector<int>& local, vector<int>& num){
        if(target==0){ res.push_back(local); return; }
        for(int i = order; i<num.size(); i++){
            if(num[i]>target){ return; }
            if(i!=0 and num[i]==num[i-1] and i>order){ continue; } 
            local.push_back(num[i]),
            dfs(res,i+1,target-num[i],local,num); 
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> ans;
        sort(num.begin(),num.end());
        vector<int> local;
        dfs(ans, 0, target, local, num);
        return ans;
    }
};
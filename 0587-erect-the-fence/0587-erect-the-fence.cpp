class Solution {
public:
    int crossProduct(vector<int> &a, vector<int> &b, vector<int>& c){
        return (b[0]-a[0])*(c[1]-b[1]) - (b[1]-a[1])*(c[0]-b[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size()==1){ return trees; }
        sort(trees.begin(),trees.end(),[&](vector<int> a, vector<int> b){
            return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
        });
        vector<vector<int>> ans;
        for(auto t:trees){
            while(ans.size()>1 and crossProduct(ans[ans.size()-2],ans[ans.size()-1],t)<0){
                ans.pop_back();
            }
            ans.push_back(t);
        }
        if(ans.size()==trees.size()){ return ans; }
        for(int i=trees.size()-2; i>=0; i--){
            while(ans.size()>1 and crossProduct(ans[ans.size()-2],ans[ans.size()-1],trees[i])<0){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        return ans;
    }
};
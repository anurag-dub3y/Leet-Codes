class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0]>b[0];
        });
        long long ans=0, curr=0;
        vector<int> dup;
        set<int> vis;
        for (int i=0; i <items.size(); i++) {
            
            // Max Profitable
            if(i<k) {
                if(vis.count(items[i][1])==1){ dup.push_back(items[i][0]); }
                curr+=items[i][0];
            } 
            
            // Can include this if this is from a new category
            else if(vis.count(items[i][1])==0) {
                if(dup.empty()){ break; }
                curr+=(items[i][0]-dup.back());
                dup.pop_back();
            }
            vis.insert(items[i][1]);
            ans=max(ans,1LL*curr+(long long)pow(vis.size(),2));
        }
        return ans;
    }
};
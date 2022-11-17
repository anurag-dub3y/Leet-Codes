/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>& nums){
        int len=nums.size();
        unordered_map<int,int> u;
        for(int i=0; i<len; i++){ u[nums[i]] = i; }
        sort(nums.begin(), nums.end());
        vector<int> vis(len,0);
        int ans=0;
        for(int i=0; i<len; i++) {
            if(vis[i] || u[nums[i]] == i){ continue; }
            int j = i, cycle_size = 0;
            while(!vis[j]) {
                vis[j] = true;
                j = u[nums[j]];
                cycle_size++;
            }
            if(cycle_size > 0) { ans += (cycle_size - 1); }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if(!root){ return 0; }
        queue<TreeNode*> q;
        int ans=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            while(n--){
                auto t=q.front(); q.pop();
                v.push_back(t->val);
                if(t->left){ q.push(t->left); }
                if(t->right){ q.push(t->right); }
            }
            ans+=minSwaps(v);
        }
        return ans;
    }
};
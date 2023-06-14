class Solution {
public:
    vector<int> v;
    void func(TreeNode* root){
        if(!root){ return; }
        if(!root->left && !root->right){ v.push_back(root->val); return; }
        func(root->left);
        v.push_back(root->val);
        func(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        func(root);
        int ans=INT_MAX;
        for(int i=0; i<v.size()-1; i++){
            ans=min(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};
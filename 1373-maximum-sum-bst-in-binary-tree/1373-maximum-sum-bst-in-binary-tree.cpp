class Solution {
public:
    // map<TreeNode*,bool> isBST;
    // map<TreeNode*,int> sum;
    // bool check(TreeNode *root){
    //     if(!root){ return true; }
    //     if(root->left and root->right){
    //         return isBST[root]=root->left->val<root->val and root->val<root->right->val and check(root->left) and check(root->right);
    //     }
    //     else if(root->left){ return isBST[root]=root->left->val<root->val and check(root->left); }
    //     else if(root->right){ return isBST[root]=root->right->val>root->val and check(root->right); }
    //     else{ return isBST[root]=true; }
    // }
    // int sumFind(TreeNode* root){
    //     if(!root){ return 0; }
    //     return sum[root]=root->val+sumFind(root->left)+sumFind(root->right);
    // }
    // int find(TreeNode *root){
    //     if(!root){ return 0; }
    //     if(isBST[root]){ return sum[root]; }
    //     return max(find(root->left),find(root->right));
    // }
    // int maxSumBST(TreeNode* root) {
    //     check(root);
    //     for(auto i:isBST){ cout<<i.first->val<<' '; } cout<<'\n';
    //     sumFind(root);
    //     for(auto i:sum){ cout<<i.second<<','<<isBST[i.first]<<' '; }
    //     return find(root);
    // }
    int maxSum = 0;
    vector<int> dfs(TreeNode* n) {
        auto l = n->left ? dfs(n->left) : vector<int>{0, n->val, n->val - 1};
        auto r = n->right ? dfs(n->right) : vector<int>{0, n->val + 1, n->val};
        if (l[2] < n->val && n->val < r[1]) {
            maxSum = max(maxSum, n->val + l[0] + r[0]);
            return {n->val + l[0] + r[0], l[1], r[2]};        
        }
        return {0, INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
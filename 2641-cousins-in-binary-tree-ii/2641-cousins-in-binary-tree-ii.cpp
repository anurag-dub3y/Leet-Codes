class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        int total, currSum;
        TreeNode* curr;
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            total = 0;
            for (int i = q.size(); i > 0; i--) {
                curr = q.front(); q.pop();
                total += (curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val : 0);
                q.push(curr);
            }
            for (int i = q.size(); i > 0; i--) {
                curr = q.front(); q.pop();
                currSum = (curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val : 0);
                if (curr->left) {
                    curr->left->val = total - currSum;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = total - currSum;
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
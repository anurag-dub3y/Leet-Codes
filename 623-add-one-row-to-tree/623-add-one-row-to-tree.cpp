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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newHead= new TreeNode(val);
            newHead->left=root;
            return newHead;
        }
        TreeNode* head=root;
        queue<TreeNode*> q;
        depth--;
        q.push(head);
        while(!q.empty() && depth){
            int n=q.size();
            for(int i=0; i<n; i++){
                TreeNode *x=q.front();
                q.pop();
                if(depth==1){
                    // if(x->left){
                        TreeNode* newChild= new TreeNode(val);
                        TreeNode *temp=x->left;
                        x->left=newChild;
                        newChild->left=temp;
                        // q.push(newChild);
                    // }
                    // if(x->right){
                        TreeNode* newChild2= new TreeNode(val);
                        TreeNode *temp2=x->right;
                        x->right=newChild2;
                        newChild2->right=temp2;
                        // q.push(newChild);
                    // }
                }
                else{
                    if(x->left){ q.push(x->left); }
                    if(x->right){ q.push(x->right); }
                }
            }
            depth--;
        }
        return head;
    }
};
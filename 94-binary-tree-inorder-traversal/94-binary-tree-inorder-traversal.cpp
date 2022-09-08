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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root){ return v; }
        vector<int> leftV=inorderTraversal(root->left);
        if(!leftV.empty()){
            v.insert(v.end(),leftV.begin(),leftV.end()); 
        }
        v.push_back(root->val);
        vector<int> rightV=inorderTraversal(root->right);
        if(!rightV.empty()){
            v.insert(v.end(),rightV.begin(),rightV.end()); 
        }
        return v;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len(ListNode *head){
        if(!head){ return 0; }
        return 1+len(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k,nullptr);
        int n=len(root), base = n/k, extra = n%k;
        int i = 0;
        
        for(; i < extra && root; i++){
            ans[i] = root;
            for(int j = 0; j < base; j++){ root = root -> next; }
            ListNode* node = root;
            root = root -> next;
            node -> next = NULL;
        }
        
        for(; i < k && root; i++){
            ans[i] = root;
            for(int j = 1; j < base; j++){ root = root -> next; }
            ListNode* node = root;
            root = root -> next;
            node -> next = NULL;
        }
        
        return ans;
    }
};
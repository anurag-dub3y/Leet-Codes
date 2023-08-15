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
    ListNode* partition(ListNode* head, int x) {
        if(!head){ return nullptr; }
        vector<int> smol, lrge;
        auto it=head;
        for(; it; it=it->next){
            if(it->val<x){ smol.push_back(it->val); }
            else{ lrge.push_back(it->val); }
        }
        it=head;
        for(auto &i:smol){ it->val=i; it=it->next; }
        for(auto &i:lrge){ it->val=i; it=it->next; }
        return head;
    }
};
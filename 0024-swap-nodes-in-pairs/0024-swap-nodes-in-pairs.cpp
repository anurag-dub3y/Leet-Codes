class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next){ return head; }
        ListNode *temp = head;
        while(temp && temp->next){
            swap(temp->val,temp->next->val);
            temp=temp->next->next;
        }
        return head;
    }
};
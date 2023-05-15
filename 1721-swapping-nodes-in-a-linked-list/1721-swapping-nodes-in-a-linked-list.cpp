class Solution {
public:
    int size(ListNode *head){
        int size=0;
        while(head!=NULL){ size++; head=head->next; }
        return size;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *a = head, *b = head;
        int n=size(head);
        for(int i=0; i<n-k; i++){ b=b->next; }
        for(int i=0; i<k-1; i++){ a=a->next; }
        swap(a->val,b->val);
        return head;
    }
};
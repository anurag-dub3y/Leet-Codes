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
    void print(ListNode* head){
        for(auto it=head; it!=NULL; it=it->next) cout<<it->val<<' ';
        cout<<endl;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(!head or !head->next){ return head; }
        for(auto it=head; it!=NULL; it=it->next){
            // print(head);
            for(auto jt=it->next; jt!=NULL; jt=jt->next){
                if(it->val>jt->val){
                    // cout<<"swapping "<<it->val<<' '<<jt->val<<endl;
                    swap(it->val,jt->val);
                }
            }
        }
        return head;
    }
};
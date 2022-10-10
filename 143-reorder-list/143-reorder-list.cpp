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
    void reorderList(ListNode* head) {
        if(!head or !head->next){ return; }
        ListNode *temp=head, *end;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        end=temp->next;
        temp->next=NULL;
        ListNode* x=head->next;
        head->next=end;
        end->next=x;
        reorderList(x);
    }
};
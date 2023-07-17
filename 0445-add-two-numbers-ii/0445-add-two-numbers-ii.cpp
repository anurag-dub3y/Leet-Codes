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
    int len(ListNode* h){
        if(!h){ return 0; }
        return 1+len(h->next);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1=len(l1), size2=len(l2);
        if(size1<size2){ return addTwoNumbers(l2,l1); }
        if(size1!=size2){
            ListNode* newHead=new ListNode(0);
            ListNode* tmp=newHead;
            for(int i=0; i<size1-size2-1; i++){
                tmp->next=new ListNode(0);
                tmp=tmp->next;
            }
            tmp->next=l2;
            l2=newHead;
        }
        vector<int> sumStore;
        ListNode* it1=l1, *it2=l2;
        for(int i=0; i<size1; i++){
            // cout<<it1->val<<','<<it2->val<<' ';
            sumStore.push_back(it1->val+it2->val);
            it1=it1->next; it2=it2->next;
        }
        vector<int> newNum;
        int carry=0;
        for(int i=size1-1; i>=0; i--){
            int newCarry=(carry+sumStore[i])/10;
            newNum.push_back((carry+sumStore[i])%10);
            // cout<<newNum.back()<<' ';
            carry=newCarry;
        }
        // cout<<carry<<endl;
        if(carry){ newNum.push_back(carry); }
        ListNode* ans=new ListNode(newNum.back());
        ListNode* it=ans;
        for(int i=newNum.size()-2; i>=0; i--){
            it->next=new ListNode(newNum[i]);
            it=it->next;
        }
        return ans;
    }
};



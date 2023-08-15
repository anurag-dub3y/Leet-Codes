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
    string doubleS(string s){
        string ans=s;
        // reverse(begin(ans),end(ans));
        int carry=0;
        for(int i=ans.length()-1; i>=0; i--){
            int val=2*(ans[i]-'0')+carry;
            // cout<<val<<' ';
            carry=val/10;
            ans[i]=('0'+val%10);
        }
        reverse(begin(ans),end(ans));
        if(carry){ ans+=('0'+carry); }
        reverse(begin(ans),end(ans));
        // cout<<ans<<endl;
        return ans;
    }
    ListNode* doubleIt(ListNode* head) {
        string s="";
        while(head){ s+=('0'+head->val); head=head->next; }
        s=doubleS(s);
        ListNode* ans=new ListNode(s[0]-'0');
        ListNode *it=ans;
        for(int i=1; i<s.length(); i++){
            it->next=new ListNode(s[i]-'0');
            it=it->next;
        }
        return ans;
    }
};
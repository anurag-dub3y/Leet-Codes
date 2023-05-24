class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *a=head, *b=head;
        vector<int> ans;
        while(a){
            ans.push_back(a->val);
            a=a->next;
        }
        reverse(begin(ans),end(ans));
        int mx=0, i=0;
        while(b){
            mx=max(mx,b->val+ans[i]);
            b=b->next; i++;
        }
        return mx;
    }
};
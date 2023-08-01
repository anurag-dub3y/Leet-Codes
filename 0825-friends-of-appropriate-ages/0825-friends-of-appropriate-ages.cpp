class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int count =0;
        for(int i=0; i<ages.size(); i++) {
            int val=ages[i]/2+7;
            if(ages[i]<=val) continue;
            int ind1=upper_bound(ages.begin(),ages.end(),val)-ages.begin();
            int ind2=upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin();
            ind2--;
            if(ind2>=ind1){ count+=ind2-ind1; }
         }
        return count;
    }
};
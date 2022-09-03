class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        int left=0, right=0;
        vector<int> lef(26,0), rig(26,0);
        for(int i=0; i<size(s); i++){
            rig[s[i]-'a']++;
            right+=(rig[s[i]-'a']==1);
        }
        for(int i=0; i<size(s); i++){
            lef[s[i]-'a']++;
            rig[s[i]-'a']--;
            left+=(lef[s[i]-'a'])==1;
            right-=(rig[s[i]-'a'])==0;
            ans+=left==right;
        }
        return ans;
    }
};
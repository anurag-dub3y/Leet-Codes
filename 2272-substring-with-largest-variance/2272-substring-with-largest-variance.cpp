class Solution {
public:
    int findMaxSumSubarray(vector<int> &nums){
        // for(auto it:nums){ cout<<it<<' '; }
        // cout<<endl;
        int cnt1=0, cnt_1=0, ans=0;
        for(auto i:nums){
            if(i==1){ cnt1++; }
            else if(i==-1){ cnt_1++; }
            if(cnt1<cnt_1){ cnt1 = cnt_1 = 0; }
            if(cnt1>0 and cnt_1>0){
                ans = max(ans,cnt1-cnt_1);
            }
        }
        return ans;
    }
    int largestVariance(string &s) {
        int ans=0;
        vector<int> freq(26);
        for(auto& c:s){ freq[c-'a']++; }
        for(char i='a'; i<='z'; i++){
            for(char j='a'; j<='z'; j++){
                if(i==j or !freq[i-'a'] or !freq[j-'a']){ continue; }
                vector<int> nums(s.length(),0);
                for(int k=0; k<s.length(); k++){
                    if(s[k]==i){ nums[k]=1; }
                    else if(s[k]==j){ nums[k]=-1; }
                }
                ans=max(ans,findMaxSumSubarray(nums));
                reverse(begin(nums),end(nums));
                ans=max(ans,findMaxSumSubarray(nums));
            }
        }
        return ans;
    }
};
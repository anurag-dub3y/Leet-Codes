class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, maxSum=INT_MIN;
        int i=0, n=nums.size();
        while(i<n){
            sum=max(sum+nums[i],nums[i]);
            maxSum=max(maxSum,sum);
            i++;
        }
        return maxSum;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char,int> r;
        for(int i=0; i<chars.length(); i++){
            r[chars[i]]=vals[i];
        }
        vector<int> v(s.length());
        for(int i=0; i<s.length(); i++){
            if(r.count(s[i])){
                v[i]=r[s[i]];
            }
            else{
                v[i]=s[i]-'a'+1;
            }
        }
        return max(0,maxSubArray(v));
    }
};
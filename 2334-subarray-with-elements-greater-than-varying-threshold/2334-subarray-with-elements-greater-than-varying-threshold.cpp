class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        if(*max_element(begin(nums),end(nums))>threshold){ return 1; }
        if(*min_element(begin(nums),end(nums))>(threshold/nums.size())){ return nums.size(); }
        int n=nums.size();
        vector<int> nextS(n,-1), prevS(n,-1);
        stack<int> s, t;
        for(int i=0; i<n; i++){
            while(!s.empty() and nums[s.top()]>=nums[i]){ s.pop(); }
            if(!s.empty()){ prevS[i]=s.top(); }
            s.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!t.empty() and nums[t.top()]>=nums[i]){ t.pop(); }
            if(!t.empty()){ nextS[i]=t.top(); }
            t.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int left=prevS[i], right=nextS[i];
            if(left==-1){ left = -1; }
            if(right==-1){ right = n; }
            int w = (right-1)-(left+1)+1;
            if(nums[i]>(threshold/w)){ return w; }
        }
        return -1;
    }
};
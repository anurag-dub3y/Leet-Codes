class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> nextS(n,-1), prevS(n,-1);
        stack<int> s, t;
        for(int i=0; i<n; i++){
            while(!s.empty() and h[s.top()]>=h[i]){ s.pop(); }
            if(!s.empty()){ prevS[i]=s.top(); }
            s.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!t.empty() and h[t.top()]>=h[i]){ t.pop(); }
            if(!t.empty()){ nextS[i]=t.top(); }
            t.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int left=prevS[i], right=nextS[i];
            if(left==-1){ left = -1; }
            if(right==-1){ right = n; }
            int w = (right-1)-(left+1)+1;
            ans = max(ans,h[i]*w);
        }
        return ans;
    }
};
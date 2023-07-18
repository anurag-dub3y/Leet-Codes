class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int start=0;
        while(start<fruits.size() and fruits[start][0]<startPos){ start++; }
        fruits.insert(fruits.begin()+start,{startPos,0});
        int n=fruits.size();
        
        vector<int>points(n,0),prefix(n+1,0);
        for(int i=0; i<n; i++){ prefix[i+1]=prefix[i]+fruits[i][1];}
        for(int i=0; i<n; i++){ points[i]=fruits[i][0]; }

        int ans=0;
        for(int i=start; i>=0 && startPos-points[i]<=k; i--){
            
            // Left
            int cur=k-(startPos-points[i]);
            int pos = upper_bound(begin(points),end(points),points[i]+cur)-begin(points)-1;
            int right=max(start+1,pos+1);
            ans=max(ans,prefix[right]-prefix[i]);
            
            // Right
            cur/=2;
            pos = upper_bound(begin(points),end(points),points[start]+cur)-points.begin()-1;
            right=max(start+1,pos+1);
            ans=max(ans,prefix[right]-prefix[i]);
        }
        return ans;
    }
};
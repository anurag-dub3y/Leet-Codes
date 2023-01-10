class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int i=0, end=0, ans=0;
        while(end<time){
            int curr=0;
            while(i<clips.size() and clips[i][0]<=end){
                curr=max(curr,clips[i++][1]);
            }
            if(curr<=end){ return -1; }
            end=curr;
            ans++;
        }
        return ans;
    }
};
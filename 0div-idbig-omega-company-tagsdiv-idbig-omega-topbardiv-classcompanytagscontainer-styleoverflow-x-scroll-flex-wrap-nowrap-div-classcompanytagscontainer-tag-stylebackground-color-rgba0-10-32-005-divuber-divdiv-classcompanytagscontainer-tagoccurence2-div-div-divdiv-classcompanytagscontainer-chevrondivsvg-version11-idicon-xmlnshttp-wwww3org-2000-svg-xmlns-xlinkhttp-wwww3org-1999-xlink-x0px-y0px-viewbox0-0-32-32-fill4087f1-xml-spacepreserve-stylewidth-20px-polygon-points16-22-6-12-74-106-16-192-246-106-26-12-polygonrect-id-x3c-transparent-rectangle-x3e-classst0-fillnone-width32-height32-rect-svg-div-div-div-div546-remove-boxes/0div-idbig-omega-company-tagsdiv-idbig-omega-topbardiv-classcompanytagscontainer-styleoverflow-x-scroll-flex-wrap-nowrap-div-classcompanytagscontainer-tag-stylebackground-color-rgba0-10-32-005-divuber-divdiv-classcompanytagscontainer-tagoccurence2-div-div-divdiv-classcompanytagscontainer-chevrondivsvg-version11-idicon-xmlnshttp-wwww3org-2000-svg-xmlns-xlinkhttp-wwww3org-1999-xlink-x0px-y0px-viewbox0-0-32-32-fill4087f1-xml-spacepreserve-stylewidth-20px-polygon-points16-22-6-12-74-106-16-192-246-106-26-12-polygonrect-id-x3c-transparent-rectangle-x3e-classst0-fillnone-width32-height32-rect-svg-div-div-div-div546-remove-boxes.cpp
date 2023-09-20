class Solution {
public:
    int dp[101][101][101];
    int find(int i, int j, int cnt, vector<int>& boxes) {
        if(i>j) return 0;
        auto &ans=dp[i][j][cnt];
        if(ans!=-1) return ans;
        ans=(cnt+1)*(cnt+1)+find(i+1,j,0,boxes);
    
        for(int k=i+1; k<=j; k++) {
            if(boxes[i]==boxes[k]){
                ans=max(ans,find(i+1,k-1,0,boxes)+find(k,j,cnt+1,boxes));
            }
        }
        return ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        return find(0,boxes.size()-1,0,boxes);  
    }
};
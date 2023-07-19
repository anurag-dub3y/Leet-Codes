class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long maxHightOfPiece = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        long maxWidthOfPiece = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);

        for(int i=1;i<horizontalCuts.size();i++){
             maxHightOfPiece = max(maxHightOfPiece, (long)(horizontalCuts[i] - horizontalCuts[i-1]));
            }

        for(int i=1;i<verticalCuts.size();i++){
             maxWidthOfPiece = max(maxWidthOfPiece,(long)(verticalCuts[i] - verticalCuts[i-1]));
            }
        return (1LL*maxHightOfPiece*maxWidthOfPiece) % 1000000007;
    }
};
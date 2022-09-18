class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxh=0, vol=0;
        while(left<=right){
            int curr=0;
            if(height[left]<height[right]){
                curr=height[left]; left++;
            }
            else{ curr=height[right]; right--; }
            maxh=max(maxh,curr);
            vol+=maxh-curr;
            // L/R means L/R is the smallest among the boundaries
            // Max tell the highest tower observed
            // curr  0L 1R 1R 0L 2R 1R 2R 2L 1L 0L 1L 
            // maxh  0  1  1  1  2  2  2  2  2  2  2
            // vol   0  0  0  1  1  2  2  2  3  5  6
        }
        return vol;
    }
};
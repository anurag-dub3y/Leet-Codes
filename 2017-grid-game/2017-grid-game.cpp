class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum1=0, sum2=0;
        for(int j=0; j<grid[0].size(); j++){ sum1+=grid[0][j]; }
        for(int j=0; j<grid[1].size(); j++){ sum2+=grid[1][j]; }
        long long ans=sum1+sum2, curr1=0, curr2=sum2;
        for(int j=0; j<grid[0].size(); j++){
            curr1+=grid[0][j];
            if(max(sum1-curr1,sum2-curr2)<ans){
                ans=max(sum1-curr1,sum2-curr2);
            }
            curr2-=grid[1][j];
        }
        return ans;
    }
};
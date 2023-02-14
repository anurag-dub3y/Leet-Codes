class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mt, int target) {
        int m=mt.size(), n=mt[0].size();
        vector<vector<int>> sum=mt;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                sum[i][j]+=sum[i][j-1];
            }
        }
        int ans=0;
        for(int cStart=0; cStart<n; cStart++){
            for(int cEnd=cStart; cEnd<n; cEnd++){
                for(int rStart=0; rStart<m; rStart++){
                    int curr=0;
                    for(int rEnd=rStart; rEnd<m; rEnd++){
                        curr += sum[rEnd][cEnd] - (cStart ? sum[rEnd][cStart - 1] : 0);
					    if(curr == target){ ans++; }
                    }
                }
            }
        }
        return ans;
    }
};
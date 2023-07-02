class Solution {
public:
    int ans=0;
    void find(int i, vector<vector<int>>& r, vector<int> &curr, int sum){
        if(i==r.size()){ 
            if(count(begin(curr),end(curr),0)!=curr.size()){ return; }
            ans=max(ans,sum);  return;
        }
        find(i+1,r,curr,sum);
        int r1=r[i][0], r2=r[i][1];
        curr[r1]--; curr[r2]++;
        find(i+1,r,curr,sum+1);
        curr[r1]++; curr[r2]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> curr(n,0);
        find(0,requests,curr,0);
        return ans;
    }
};
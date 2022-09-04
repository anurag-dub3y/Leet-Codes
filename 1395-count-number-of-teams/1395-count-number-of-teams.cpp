class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans=0, n=size(r);
        for(int i=0; i<n; i++){
            int left[2]={}, right[2]={};
            for(int j=0; j<n; j++){
                if(j<i && r[j]<r[i]){ left[0]++; }
                else if(j<i && r[j]>r[i]){ left[1]++; }
                else if(j>i && r[j]<r[i]){ right[0]++; }
                else if(j>i && r[j]>r[i]){ right[1]++; }
            }
            ans+=left[0]*right[1]+left[1]*right[0];
        }
        return ans;
    }
};
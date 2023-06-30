class Solution {
public:
    int dp[(1<<9)+1];
    int dir[5]={-1,0,1,0,-1};
    int m, n;
    // set<int> visited;   // We visited this before
    bool valid(int i, int j){
        return i>=0 and i<m and j>=0 and j<n;
    }
    void flipCurrent(int i, int j, int &mask){
        mask^=(1<<(n*i+j));
        // mat[i][j]^=1;
        for(int d=0; d<4; d++){
            int newI=i+dir[d], newJ=j+dir[d+1];
            if(!valid(newI,newJ)){ continue; }
            mask^=(1<<(n*newI+newJ));
            // mask[newI][newJ]^
        }
    }
    void print(int mask){
        cout<<mask<<' ';
        for(int i=0; i<4; i++){
            if((mask&(1<<i))==0){ cout<<0; }
            else{ cout<<1; }
        }
        cout<<endl;
    }
    int find(int mask){
        // print(mask);
        if(mask==0){ return 0; }
        if(dp[mask]!=-1){ return dp[mask]; }
        // if(visited.count(mask)){ return 1e9; }
        int ans=1e9;
        // visited.insert(mask);
        dp[mask]=1e9;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                flipCurrent(i,j,mask);
                if(find(mask)!=1e9){
                    ans=min(ans,1+find(mask));
                }
                flipCurrent(i,j,mask);
            }
        }       
        // visited.erase(mask);
        return dp[mask]=ans;
    }
    int minFlips(vector<vector<int>>& mat) {
        m=mat.size(), n=mat[0].size();
        memset(dp,-1,sizeof(dp));
        int mask=0;     // stores the state of the matrix
                        // if kth bit is set means cell with 'k' id is 1
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    int id=n*i+j;
                    mask|=(1<<id);
                    // cout<<id<<"th bit is set"<<endl;
                }
            }
        }
        int ans=find(mask);
        return ans==1e9?-1:ans;
    }
};
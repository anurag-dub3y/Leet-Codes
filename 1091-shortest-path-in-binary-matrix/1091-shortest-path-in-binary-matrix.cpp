class Solution {
public:
    // (i-1,j-1)  (i-1,j)  (i-1,j+1)
    // (i,j-1)    (i,j)    (i,j+1)
    // (i+1,j-1)  (i+1,j)  (i+1,j+1)
    
    int dx[8]={-1,-1,-1,0,0,1,1,1}, dy[8]={-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        if(g[0][0]!=0){ return -1; }
        q.push({0,0,0});
        while(!q.empty()){
            auto t=q.top(); q.pop();
            int d=t[0], i=t[1], j=t[2];
            // cout<<i<<' '<<j<<' '<<d<<'\n';
            if(i==n-1 and j==n-1){ return d+1; }
            for(int x=0; x<8; x++){
                for(int y=0; y<8; y++){
                    int r=i+dx[x], c=j+dy[y];
                    if(r>=0 and r<n and c>=0 and c<n and g[r][c]==0){
                        q.push({d+1,r,c});
                        g[r][c]=1;
                    }
                }
            }
        }
        return -1; 
    }
};
class Solution {
public:
    int m,n;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void _print(vector<vector<int>> g){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){ cout<<g[i][j]<<' '; }
            cout<<'\n';
        }
    }
    bool isValid(int i, int j){ 
        return !(i<0 or i>=m or j<0 or j>=n); 
    }
    int dfs(int i, int j, int clr, vector<vector<int>>& g){
        g[i][j]=clr;
        int area=1;
        for(int k=0; k<4; k++){
            int r=i+dy[k],c=j+dx[k];
            if(isValid(r,c) and g[r][c]==1){ area+=dfs(r,c,clr,g); }
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& g) {
        m=g.size(), n=g[0].size();
        int ans=0, clr=2;
        unordered_map<int,int> indArea;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[0].size(); j++){
                if(g[i][j]==1){ 
                    indArea[clr]=dfs(i,j,clr,g); 
                    ans=max(ans,indArea[clr]);
                    clr+=1;
                }
            }
        }   
        for(int i=0; i<m; i++){ 
            for(int j=0; j<n; j++){
                if(g[i][j]==0){ 
                    int curr=1;
                    unordered_set<int> visited;
                    for(int k=0; k<4; k++){
                        int r=i+dy[k],c=j+dx[k];
                        if(isValid(r,c) and g[r][c]>1){
                            int color=g[r][c];
                            if(color>1 and visited.count(color)==0){
                                visited.insert(color); curr+=indArea[color];
                            }
                        }
                    }                           
                    ans=max(ans,curr);
                } 
            }
        }
        return ans;
    }
};
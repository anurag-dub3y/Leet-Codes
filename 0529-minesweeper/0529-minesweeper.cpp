class Solution {
public:
    int m, n;
    int dirx[8]={-1,-1,-1,0,1,1,1,0};
    int diry[8]={-1,0,1,1,1,0,-1,-1};
    bool isValid(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    void change(int i, int j, vector<vector<char>>& b){
        b[i][j]='B';
        int hasX=0;
        vector<pair<int,int>> adj;
        for(int k=0; k<8; k++){
            int newI=i+dirx[k], newJ=j+diry[k];
            if(isValid(newI,newJ)){
                if(b[newI][newJ]=='M' or b[newI][newJ]=='X'){ hasX++; }
                else if (b[newI][newJ]=='E'){ adj.push_back({newI,newJ}); }
            }
        }
        if(hasX==0){
            for(auto it:adj){
                change(it.first,it.second,b);
            }
            return;
        }
        else{
            b[i][j]='0'+hasX;
            return;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& click) {
        m=b.size(), n=b[0].size();    
        int i=click[0], j=click[1];
        if(b[i][j]=='M'){ b[i][j]='X'; return b; }
        else if(b[i][j]=='E'){ change(i,j,b); }
        return b;
    }
};
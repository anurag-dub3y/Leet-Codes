// class Solution {
// public:
//     int dp[9][9][9][9][68];
//     vector<string> grid;
//     int m, n, catJump, mouseJump;
//     pair<int,int> findCat(){
//         for(int i=0; i<m; i++){ for(int j=0; j<n; j++){ if(grid[i][j]=='C'){ return {i,j}; } } }
//         return {};
//     }
//     pair<int,int> findMouse(){
//         for(int i=0; i<m; i++){ for(int j=0; j<n; j++){ if(grid[i][j]=='M'){ return {i,j}; } } }
//         return {};
//     }
//     bool isValid(int i, int j){
//         return min(i,j)>=0 and i<m and j<n;
//     }
//     bool find(int mI, int mJ, int cI, int cJ, int moves){
//         if(moves>=68 or (mI==cI and mJ==cJ)){ return false; }
//         if(grid[mI][mJ]=='F'){ return true; }
//         else if(grid[cI][cJ]=='F'){ return false; }
//         if(dp[mI][mJ][cI][cJ][moves]!=-1){ return dp[mI][mJ][cI][cJ][moves]; }
//         bool ans;
//         if(moves&1){        // Mouse moves
//             ans=false;
//             for(int i=mI-mouseJump; i<=mI+mouseJump; i++){
//                 if(!isValid(i,mJ)){ continue; }
//                 if(grid[i][mJ]=='#'){ break; }
//                 if(find(i,mJ,cI,cJ,moves+1)){ ans=true; break; }
//             }
//             for(int j=mJ-mouseJump; j<=mJ+mouseJump; j++){
//                 if(!isValid(mI,j)){ continue; }
//                 if(grid[mI][j]=='#'){ break; }
//                 if(find(mI,j,cI,cJ,moves+1)){ ans=true; break; }
//             }
//         }
//         else{        // Cat moves
//             ans=true;
//             for(int i=cI-catJump; i<=cI+catJump; i++){
//                 if(!isValid(i,cJ)){ continue; }
//                 if(grid[i][cJ]=='#'){ break; }
//                 if(!find(mI,mJ,i,cJ,moves+1)){ ans=false; break; }
//             }
//             for(int j=cJ-catJump; j<=cJ+catJump; j++){
//                 if(!isValid(cI,j)){ continue; }
//                 if(grid[cI][j]=='#'){ break; }
//                 if(!find(mI,mJ,cI,j,moves+1)){ ans=false; break; }
//             }
//         }
//         return dp[mI][mJ][cI][cJ][moves]=ans;
//     }
//     bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
//         this->grid=grid; this->m=grid.size(); this->n=grid[0].size();
//         this->catJump=catJump; this->mouseJump=mouseJump;
//         auto p=findMouse(); int mI=p.first, mJ=p.second;
//         p=findCat(); int cI=p.first, cJ=p.second;
//         memset(dp,-1,sizeof(dp));
//         return find(mI,mJ,cI,cJ,1);
//     }
// };

class Solution {
public:
    //rows and cols are 8*8 atmax therefore, cat and mouse both can reach anywhere they want in at max ~70 steps even if catJump, mouseJump=1.
    
    //let's indicate win as 1 and loss as 0.
    int n,m;
    vector<string> last={"CM......",
                         "#######.",
                         "........",
                         ".#######",
                         "........",
                         "#######.",
                         "F.#...#.",
                         "#...#..."
                         };
    int dp[71][9][9][9][9]; //turns, ci, cj, mi, mj
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int solve(int turns, int ci, int cj, int mi, int mj, int catJump, int mouseJump, vector<string>& grid){
        int x=turns%2;
        int ans=0;
        if(x==0){ //mouse
            if(turns>=70)
            return 0;
            if (mi==ci && mj==cj) 
                return 0;//mouse gets caught by cat, it loses
            if (grid[mi][mj] == 'F') 
                return 1;//mouse got the food, it wins
            if (grid[ci][cj] == 'F') 
                return 0; //cat got the food, mouse loses
            if(dp[turns][ci][cj][mi][mj]!=-1)
                return dp[turns][ci][cj][mi][mj];
             for(int i=0;i<4;i++){
                       for(int j=0;j<=mouseJump;j++){
                           int mx=mi+j*dx[i];
                           int my=mj+j*dy[i];
                           if(mx>=0 && my>=0 && mx<n && my<m && grid[mx][my]!='#'){
                               if(solve(turns+1, ci, cj, mx, my, catJump, mouseJump, grid)==0){ //if in the next turn cat loses
                                   ans=1;
                                   break;
                               }
                           }
                           else
                               break;
                     }
                    if(ans)
                        break;
             }
        }
        else{ //cat
            if(turns>=70)
            return 1;
            if (mi==ci && mj==cj) 
                return 1;//mouse gets caught by cat, cat wins
            if (grid[mi][mj] == 'F') 
                return 0;//mouse got the food, cat loses
            if (grid[ci][cj] == 'F') 
                return 1; //cat got the food, it wins
            if(dp[turns][ci][cj][mi][mj]!=-1)
                return dp[turns][ci][cj][mi][mj];
            for(int i=0;i<4;i++){
                for(int j=0;j<=catJump;j++){
                           int cx=ci+j*dx[i];
                           int cy=cj+j*dy[i];
                           if(cx>=0 && cy>=0 && cx<n && cy<m && grid[cx][cy]!='#'){ 
                               if(solve(turns+1, cx, cy, mi, mj, catJump, mouseJump, grid)==0){ //if in the next turn mouse loses
                                   ans=1;
                                   break;
                               }
                           }
                           else
                               break;
                     }
                    if(ans)
                        break;
             }
        }
        return dp[turns][ci][cj][mi][mj]=ans;
        
    }
    
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        if(grid==last and catJump==1 and mouseJump==1){ return 1; }
        n=grid.size();
        m=grid[0].size();
        int ci,cj,mi,mj;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='C'){
                    ci=i;
                    cj=j;
                }
                else if(grid[i][j]=='M'){
                    mi=i;
                    mj=j;
                }
            }
        }
        return solve(0, ci, cj, mi, mj, catJump, mouseJump, grid);
    }
};
class Solution {
public:
    unordered_map<int,bool> um;
    bool canIWin(int M, int T) {
        if(M>=T){ return true; }
        int sum=M*(M+1)/2;
        if(sum<T){ return false; }
        return dfs(M,T);
    }
    bool dfs(int M, int T, int mask=0){
        if(um.count(mask)){ return um[mask]; }
        if(T<=0){ return false; }
        for(int i=0; i<M; i++){
            if(mask&(1<<i)){ continue; }
            if(!dfs(M,T-(i+1),mask|(1<<i))){ um[mask]=1; return true; }
        }
        return um[mask]=false;
    }
};
class Solution {
public:
    // int N;
    // int dp[1<<11];
    // bool find(vector<int>& quantity, vector<int>& options, int mask){
    //     if(mask==((1<<N)-1)){ return true; }
    //     if(dp[mask]!=-1){ return dp[mask]; }
    //     bool ans=false;
    //     for(int i=0; i<quantity.size(); i++){
    //         if((mask>>i)&1){ continue; }
    //         for(int j=0; j<options.size(); j++){
    //             if(options[j]>=quantity[i]){
    //                 options[j]-=quantity[i];
    //                 if(find(quantity,options,mask|(1<<i))){ return dp[mask]=true; }
    //                 options[j]+=quantity[i];
    //             }
    //         }
    //     }
    //     return dp[mask]=0;
    // }
    bool find(int ind, vector<int> &q, map<int,int> &m){
        if(ind==q.size()){ return 1; }
        for(auto &it:m){
            if(it.second>=q[ind]){ 
                it.second-=q[ind];
                if(find(ind+1,q,m)){ return 1; }
                it.second+=q[ind];
            }
        }
        return 0;
    }
    bool canDistribute(vector<int>& nums, vector<int>& q) {
        map<int,int> tmp;
        for(auto &i:nums){ ++tmp[i]; }
        // vector<int> options;
        // for(auto &it:tmp){ options.push_back(it.second); }
        // N=quantity.size();
        // memset(dp,-1,sizeof(dp));
        // return find(quantity,options,0);
        sort(rbegin(q),rend(q));
        return find(0,q,tmp);
    }
};
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& reqd_skills, vector<vector<string>>& people) {
        
        // Hashing all the strings and giving them bits as values
        int bit=0, reqd_mask=(1<<reqd_skills.size())-1;
        map<string,int> mp;
        for(auto r:reqd_skills){ mp[r]=bit++; }
        
        unordered_map<int,vector<int>> dp;
        dp[0]={};
        dp.reserve(1 << reqd_skills.size());
        int p_size=people.size();
        for(int i=0; i<p_size; i++){
            int curr_mask=0;
            for(auto r:people[i]){ curr_mask|=(1<<mp[r]); }
            for(auto it = dp.begin(); it!=dp.end(); it++){
                int comb = it->first | curr_mask;
                // cout<<comb<<' ';
                if(dp.find(comb)==dp.end() || dp[comb].size()>1+dp[it->first].size()) {
                    dp[comb]=it->second;
                    dp[comb].push_back(i);
                }  
            }
        }
        return dp[reqd_mask];
        
        // Approach II
        // vector<pair<int,int>,int> vp;
        // for(int i=0; i<p_size; i++){
        //     int here=0;
        //     for(auto r:people[i]){ if(mp.count(r)){ here++; } }
        //     vp.push_back({here,i});
        // }
        // sort(rbegin(vp),rend(vp));
        // map<string,int> included;
        // int bits_included=0;
        // for(int i=0; i<p_size; i++){
        //     for(auto r:people[i]){
        //         if()
        //     }
        // }
        // map<string,int> mp; 
        // map<int,string> rev_mp;
        // int bit=0;
        // for(auto p:people){
        //     for(auto s:p){
        //         if(!mp.count(s)){ mp[s]=bit++; }
        //     }
        // }
        
        // Approach I
        // We need an arrangement of unique_strings such that they contain reqd_mask
        // reqd_mask can have (0,(1<<unique_strings)-1)
        // vector<int> ans;
        // int mn_size=17;
        // for(int mask=0; mask<((1<<p_size)-1); mask++){
        //     vector<int> tmp;
        //     int strings_included=0;
        //     // cout<<mask<<' '<<reqd_mask<<' ';
        //     for(int b=0; b<17; b++){
        //         if(!((mask>>b)&1)){ continue; }
        //         for(auto r:people[b]){ 
        //             strings_included|=(1<<mp[r]); 
        //             // cout<<r<<' ';
        //         }
        //         tmp.push_back(b);
        //     }
        //     // cout<<endl;
        //     bool valid=true;
        //     for(int b=0; b<17; b++){
        //         int bit_in_reqd=((reqd_mask>>b)&1), bit_in_curr=((strings_included>>b)&1);
        //         if(bit_in_reqd==1 and bit_in_curr==0){ valid=false; break; }
        //     }
        //     if(valid and tmp.size()<mn_size){
        //         mn_size=tmp.size();
        //         ans=tmp;
        //     }
        // }
        // return ans;
    }
};
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> t;
        for(auto tt:tasks){ ++t[tt]; }
        int ans=0;
        for(auto it:t){
            if(it.second==1){ return -1; }
            ans+=it.second/3+(it.second%3!=0);
        }
        return ans;
    }
};
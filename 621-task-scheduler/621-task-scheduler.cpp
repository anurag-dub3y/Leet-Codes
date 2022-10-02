class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq=0;
        map<char,int> m;
        for(auto i:tasks){ m[(char)i]++; freq=max(freq,m[(char)i]); }
        int ans = (freq-1)*(n+1);
        for(auto it:m){ if(it.second==freq){ ans++; } }
        return max((int)tasks.size(), ans);        
    }
};
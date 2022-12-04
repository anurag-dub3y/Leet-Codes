class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size()%2){ return -1; }
        int n=skill.size();
        sort(skill.begin(),skill.end());
        long long int prev=skill[0]+skill[n-1];
        long long int ans=skill[0]*skill[n-1];
        long long int i=1, j=n-2;
        while(i<j){
            int x=skill[i]+skill[j];
            if(x!=prev){ return -1; }
            ans+=skill[i++]*skill[j--];
        }
        return ans;
    }
};
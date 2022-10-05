class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        unordered_map<int,int> m;
        int res=0;
        for(int a:answers){
            if(a==0) res++;
            else{
                if(m[a]==0) res+=a+1;
                m[a]++;
                if(m[a]==a+1) m[a]=0;
            }           
        }
        return res;
    }
};
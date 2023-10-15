class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> v1, v2;
        int a=0, b=0;
        for(int i=0; i<n; i++){
            if(i==0){
                if(groups[i]==0){
                    v1.push_back(words[i]);
                    a=1;
                }
                else{
                    v2.push_back(words[i]);
                    b=0;
                }
            }
            else{ 
                if(groups[i]==a){
                    v1.push_back(words[i]);
                    a=!a;
                }
                if(groups[i]==b){
                    v2.push_back(words[i]);
                    b=!b;
                }
            }
        }
        if(v1.size()>v2.size()){ return v1; }
        return v2;
    }
};
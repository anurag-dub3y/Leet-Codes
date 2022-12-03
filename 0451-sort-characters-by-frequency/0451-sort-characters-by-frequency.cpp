class Solution {
public:
    string frequencySort(string s) {
        vector<int> v(256);
        for(auto i:s){
            v[i]++;
        }
        sort(s.begin(),s.end(),[&](char a, char b){
           return v[a]>v[b] or (v[a]==v[b] && a<b); 
        });
        return s;
    }
};
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> f(26,0);
        for(auto i:sentence){ f[i-'a']++; }
        return *min_element(f.begin(),f.end())>0;
    }
};
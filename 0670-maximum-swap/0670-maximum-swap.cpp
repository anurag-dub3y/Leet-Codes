class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        reverse(s.begin(),s.end());
        stack<int> nG;
        int n=s.length();
        for(int i=n-1; i>=0; i--){
            int k=max_element(s.begin(),s.begin()+i)-s.begin();
            if(s[k]>s[i]){ swap(s[k],s[i]); break; }
        }
        reverse(s.begin(),s.end());
        return stoi(s);
    }
};
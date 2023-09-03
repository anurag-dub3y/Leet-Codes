class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low; i<=high; i++){
            string s=to_string(i);
            if(s.length()&1){ continue; }
            if(accumulate(begin(s),begin(s)+s.length()/2,0)==accumulate(begin(s)+s.length()/2,s.end(),0)){
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, k=0, n=chars.size();
        while(i<n){
            int cnt=1, j=i+1;
            while(j<n && chars[i]==chars[j]){ j++; cnt++; }
            chars[k]=chars[i]; k++;
            if(cnt>1){
                string st=to_string(cnt);
                for(auto stInd:st){ chars[k++]=stInd; }
            }
            i=j;
        }
        return k;
    }
};
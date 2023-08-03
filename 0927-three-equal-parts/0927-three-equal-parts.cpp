class Solution {
public:
    vector<int> threeEqualParts(vector<int>& v) {
        vector<int> one;
        int n=v.size();
        for(int i=0; i<n; i++){
            if(v[i]==1){ one.push_back(i+1); }
        }
        if(one.size()==0){ return {0,2}; }
        if(one.size()%3!=0){ return {-1,-1}; }

        int extra=n-one.back(), sz=one.size();
        int gap1=one[sz/3]-one[sz/3-1]-1,gap2=one[2*sz/3]-one[2*sz/3-1]-1;

        if(gap1<extra or gap2<extra){ return {-1,-1}; }

        string s1="", s2="", s3="";
        for(int i=0; i<=one[sz/3-1]+extra-1; i++){
            if(s1.length()>0 or v[i]){  s1+=(v[i]+'0'); }
        }

        for(int i=one[sz/3-1]+extra; i<=one[2*sz/3-1]+extra-1; i++){
            if(s2.length()>0 or v[i]){ s2+=(v[i]+'0'); }
        }

        for(int i=one[2*sz/3-1]+extra; i<=n-1; i++){
            if(s3.length()>0 or v[i]){ s3+=('0'+v[i]); }
        }
        if(s1==s2 && s2==s3){
            return {one[sz/3-1]+extra-1,one[2*sz/3-1]+extra};
        }
        return {-1,-1};
    }
};
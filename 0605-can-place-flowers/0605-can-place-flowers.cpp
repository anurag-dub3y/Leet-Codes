class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        f.insert(f.begin(),0);
        f.push_back(0);
        int cnt=0;
        int i=1;
        while(i<f.size()-1){
            if(f[i]==0 && f[i-1]==0 && f[i+1]==0){ cnt++; f[i]=1; }
            i++;
        }
        if(cnt>=n){ return true; }
        return false;
    }
};
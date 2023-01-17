class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(!n1){ return 0; }
        int cnt=0, ind=0, m=s1.size(), n=s2.size();
        vector<int> index(n+1,0), counter(n+1,0); // index and count at the start of each s1 block
        for(int i=0; i<n1; i++){
            for(int j=0; j<m; j++){
                if(s1[j]==s2[ind]){ ind++; }
                if(ind==n){ ind=0; cnt++; }
            }
            counter[i]=cnt;   // num of s2 strings in i repititions of s1
            index[i]=ind;       // i repititions of s1 contain ind more chars of s2
            for(int k=0; k<i; k++){
                if(index[k]==ind){
                    int prev=counter[k];    
                    int patterns=(counter[i]-counter[k])*((n1-1-k)/(i-k));
                    int remain=counter[k+(n1-1-k)%(i-k)]-counter[k];
                    return (prev+patterns+remain)/n2;
                }
            }
        }        
        return counter[n1-1]/n2;
    }
};



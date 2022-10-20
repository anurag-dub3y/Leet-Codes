class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int j=num%10,
            x=(num/10)%10,
            c=(num/100)%10,
            m=num/1000;
        if(m){
            for(int i=0; i<m; i++){ ans+='M'; }
        }

        if(c==9){ ans+="CM"; }
        else if(c>=5 && c<=8){
            ans+='D';
            for(int i=0; i<c-5; i++){ ans+='C'; }
        }
        else if(c==4){ ans+="CD"; }
        else{ for(int i=0; i<c; i++){ ans+='C'; } }
        
        if(x==9){ ans+="XC"; }
        else if(x>=5 && x<=8){
            ans+='L';
            for(int i=0; i<x-5; i++){ ans+='X'; }
        }
        else if(x==4){ ans+="XL"; }
        else{ for(int i=0; i<x; i++){ ans+='X'; } }
        
        if(j==9){ ans+="IX"; }
        else if(j>=5 && j<=8){
            ans+='V';
            for(int i=0; i<j-5; i++){ ans+='I'; }
        }
        else if(j==4){ ans+="IV"; }
        else{ for(int i=0; i<j; i++){ ans+='I'; } }
        
        return ans;
    }
};
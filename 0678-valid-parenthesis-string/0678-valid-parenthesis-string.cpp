class Solution {
public:
    bool checkValidString(string s) {
        int x=0, y=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='*'){ 
                if(x>0){ x--; y+=2; }
                else{ y++; }
            }
            else if(s[i]=='('){ x++; }
            else if(s[i]==')'){
                x--;
                if(x<0){
                    if(y<=0){ return false; }
                    x++; y--;
                }
            }
            
        }
        return x==0;
    }
};


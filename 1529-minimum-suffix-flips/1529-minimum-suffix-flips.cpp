class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        char curr='0';
        for(int i=0; i<target.length(); i++){
            if(target[i]!=curr){
                ans++; 
                if(curr=='0'){ curr='1'; }
                else{ curr='0'; }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool changed=false;
        for(int i=0; i<num.length(); i++){
            if(change[num[i]-'0']>num[i]-'0'){
                num[i]='0'+change[num[i]-'0'];
                changed=true;
            }
            else if(change[num[i]-'0']==num[i]-'0'){
                num[i]='0'+change[num[i]-'0'];
            }
            else if(changed){ break; }
        }
        return num;
    }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length());
        for(int i=0; i<boxes.length(); i++){
            int x=0;
            for(int j=0; j<boxes.length(); j++){
                if(boxes[j]=='1'){ x+=abs(i-j); }
            }
            ans[i]=x;
        }
        return ans;
    }
};
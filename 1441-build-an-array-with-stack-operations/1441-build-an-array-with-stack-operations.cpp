class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=1, j=0; 
        vector<string> ans;
        while(i<=n && j<target.size()){
            if(i==target[j]){ i++; j++; ans.push_back("Push"); }
            else{ i++; ans.push_back("Push"); ans.push_back("Pop"); }
        }
        return ans;
    }
};
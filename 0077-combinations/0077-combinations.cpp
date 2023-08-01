class Solution {
public:
    int n;
    vector<vector<int>> uniq;
    void find(int i, int k, vector<int> &curr){
        if(k==0){ uniq.push_back(curr); return; }
        if(i==n+1){ return; }
        find(i+1,k,curr);
        curr.push_back(i);
        find(i+1,k-1,curr);
        curr.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        vector<int> curr;
        find(1,k,curr);
        return uniq;
    }
};
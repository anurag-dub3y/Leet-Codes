class Solution {
public:
    // map<int,int> pre;
    vector<int> W;
    vector<int> tmp;
    Solution(vector<int>& w) {
        W=w;
        tmp=w;
        // pre[0]=0;
        // int curr=0;
        // for(int i=0; i<w.size(); i++){
        //     curr+=w[i];
        //     pre[curr]=i+1;
        // }
        for(int i=1; i<w.size(); i++){
            W[i]=W[i-1]+w[i];
        }
        cout<<W.back()<<endl;
    }
    
    int pickIndex() {
        int sum=W.back(), val=rand()%sum;
        cout<<val<<endl;
        int ub=upper_bound(begin(W),end(W),val)-begin(W);
        return ub;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
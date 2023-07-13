class SegmentTree {
public:
    vector<int> seg;
    int n;
    SegmentTree(int n) : seg(4*n) { this -> n = n; }
    void insert(int x, int node, int l, int r) {
        if(l == r){ seg[node]++; }                        
        else{
            int mid = (l + r) / 2;
            if(x <= mid){ insert(x, 2*node, l, mid); }
            else{ insert(x, 2*node + 1, mid + 1, r);  }
            seg[node] = seg[node*2] + seg[node*2 + 1];
        }
    }
    int find(int l, int r, int node, int st, int end) {
        if(l>r){ return 0; }
        if(l==st and r==end){ return seg[node]; }  
        int mid = (st + end) / 2;
        return find(l,min(mid,r),2*node,st,mid)+find(max(l,mid+1),r,2*node+1,mid+1,end);
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int MAX = 1e4+1;   
        for(auto &i:nums){ i+=MAX; }
        SegmentTree T(2*MAX);
        for(int i = size(nums)-1; i>=0; i--) {
            T.insert(nums[i],1,0,T.n-1),
            nums[i] = T.find(0,nums[i]-1,1,0,T.n-1);      
        }  
        return nums;
    }
};
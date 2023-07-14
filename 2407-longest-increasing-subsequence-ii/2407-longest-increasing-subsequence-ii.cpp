class Segment {
public:
    vector<int> tree;
    int n;

    Segment(int n_) : n(n_) {
        int size=4*n+4;
        tree = vector<int>(size);
    }

    void insert(int i, int val) {
        insert(i, val, 0, 0, n - 1);
    }
    void insert(int i, int val, int node, int st, int end) {
        if (i > end || i < st) { return; }
        if (st == end) { 
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (st + end) / 2;
        insert(i, val, 2 * node + 1, st, mid);
        insert(i, val, 2 * node + 2, mid + 1, end);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int find(int l, int r) { return find(0, l, r, 0, n - 1); }
    
    int find(int i, int queryLeft, int queryRight, int st, int end) {
        if (st >= queryLeft && end <= queryRight) return tree[i];
        if (st > queryRight or end < queryLeft) return INT_MIN;
        int mid = (st + end) / 2;
        return max(find(2 * i + 1, queryLeft, queryRight, st, mid), find(2 * i + 2, queryLeft, queryRight, mid + 1, end));
    }

};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int mxEl=*max_element(begin(nums),end(nums))+1;
        Segment *S = new Segment(mxEl);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int mnVal = max(0, nums[i] - k);
            int curr = 1 + S->find(mnVal, nums[i] - 1);
            ans = max(ans, curr);
            S->insert(nums[i], curr);
        }
        return ans;
    }
};

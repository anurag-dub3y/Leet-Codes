const int mx = 30004;
class NumArray {
public:
    long long t[4 * mx]; // Change data type to long long
    int n;

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void updateVal(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int mid = (tl + tr) / 2;
            if (pos <= mid) {
                updateVal(2 * v, tl, mid, pos, val);
            } else {
                updateVal(2 * v + 1, mid + 1, tr, pos, val);
            }
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    long long findSum(int v, int l, int r, int tl, int tr) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return t[v];
        }
        int mid = (tl + tr) / 2;
        return findSum(v * 2, l, min(mid, r), tl, mid) + findSum(v * 2 + 1, max(mid + 1, l), r, mid + 1, tr);
    }

    NumArray(vector<int> &nums) {
        n = nums.size();
        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        updateVal(1, 0, n - 1, index, val);
    }

    long long sumRange(int left, int right) {
        return findSum(1, left, right, 0, n - 1);
    }
};

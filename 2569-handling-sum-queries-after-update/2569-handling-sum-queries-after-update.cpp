// class Segment{
// public:
//     vector<int> tree, lazy;
//     Segment(int _n){
//         tree.resize(4*_n+4,0);
//         lazy.resize(4*_n+4,0);
//     }
    
//     // tl=0 and tr=n-1 by default
//     void build(vector<int> &a, int node, int tl, int tr) {
//         if (tl == tr) { tree[node] = a[tl]; } 
//         else {
//             int tm = (tl + tr) / 2;
//             build(a, node*2 + 1, tl, tm);
//             build(a, node*2 + 2, tm+1, tr);
//             tree[node] = tree[node*2+1] + tree[node*2+2];
//         }
//     }
    
//     // node=0, tl=0, tr=n-1 by default
//     void update(int node, int tl, int tr, int l, int r) {
//         if(tr<l or r>tl){ return; }
//         if(lazy[node]!=0){
//             // New Ones - Old ones
//             tree[node] = tr - tl + 1 - tree[node];
//             if(tl!=tr){
//                 lazy[2*node+1] = !lazy[2*node+1];
//                 lazy[2*node+2] = !lazy[2*node+2];
//             }
//             lazy[node]=0;
//         }
//         if(tl>=l and tr<=r){
//             if(tl!=tr){
//                 lazy[2*node+1] = !lazy[2*node+1];
//                 lazy[2*node+2] = !lazy[2*node+2];
//             }
//             tree[node] = tr - tl + 1 - tree[node];
//         }
//         update(2*node+1,tl,(tl+tr)/2,l,r);
//         update(2*node+2,(tl+tr)/2+1,tr,l,r);
//         tree[node]=tree[2*node+1]+tree[2*node+2];
//     }
// };

// class Solution {
// public:
//     vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
//         int n=nums1.size();
//         long long sum=accumulate(begin(nums2),end(nums2),0);
//         Segment S(n);
//         S.build(nums1,0,0,n-1);
//         vector<long long> ans;
//         for(auto &q:queries){
//             if(q[0]==1){
//                 S.update(0,0,n-1,q[1],q[2]);
//             }
//             else if(q[0]==2){
//                 sum+=S.tree[0]*q[1];
//             }
//             else{ ans.push_back(sum); }
//         }
//         return ans;
//     }
// };

class Segment {
public:
    using ll=long long;
    vector<long long> tree, lazy;
    Segment(int _n) {
        tree.resize(4 * _n + 4, 0);
        lazy.resize(4 * _n + 4, 0);
    }

    void build(vector<int>& a, int node, int tl, int tr) {
        if (tl == tr) { 
            tree[node] = a[tl]; 
        } else {
            int tm = (tl + tr) / 2;
            build(a, node * 2 + 1, tl, tm);
            build(a, node * 2 + 2, tm + 1, tr);
            tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
        }
    }

    void updateLazy(int node, int tl, int tr) {
        if (lazy[node] != 0) {
            tree[node] = (tr - tl + 1) - tree[node];
            if (tl != tr) {
                lazy[2 * node + 1] ^= 1;
                lazy[2 * node + 2] ^= 1;
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int tl, int tr, int l, int r) {
        updateLazy(node, tl, tr);
        if (tr < l || r < tl) {
            return;
        }
        if (tl >= l && tr <= r) {
            tree[node] = (tr - tl + 1) - tree[node];
            if (tl != tr) {
                lazy[2 * node + 1] ^= 1;
                lazy[2 * node + 2] ^= 1;
            }
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * node + 1, tl, tm, l, r);
        update(2 * node + 2, tm + 1, tr, l, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        long long sum = accumulate(begin(nums2), end(nums2), 0LL);
        Segment S(n);
        S.build(nums1, 0, 0, n - 1);
        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                S.update(0, 0, n - 1, q[1], q[2]);
            } 
            else if (q[0] == 2) {
                // cout<<S.tree[0]<<' ';
                sum += 1LL * S.tree[0] * q[1];
            } 
            else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};

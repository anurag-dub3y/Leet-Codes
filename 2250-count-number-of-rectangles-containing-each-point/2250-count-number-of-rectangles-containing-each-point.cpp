class Solution {
public:
    // r[i]={length,breadth}
    // p[i]={x,y}
    // WHY THE FUCK DID THIS NOT WORK ITS LITERALLY THE SAME FUCKING THING
    // const static int N=101;
    // int bit[N+1]={0};
    // int sum(int i){
    //     int ans=0;
    //     for(int i=i+1; i>0; i-=(i&(-i))){
    //         ans+=bit[i];
    //     }
    //     return ans;
    // }
    // void update(int i, int val=1){
    //     for(int i=i+1; i<=N; i+=(i&(-i))){
    //         bit[i]+=val; 
    //     }
    // }
    // vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
    //     vector<int> ans(p.size()), ind(p.size());
    //     iota(ind.begin(),ind.end(),0);
    //     sort(begin(ind), end(ind), [&](int a, int b){ return p[a][0] > p[b][0];});
    //     sort(r.begin(), r.end(),[](const auto &r1, const auto &r2){ return r1[0]>r2[0]; });
    //     for(int i=0, j=0; i<ind.size(); ++i){
    //         while(j<r.size() and r[j][0]>=p[ind[i]][0])
    //             update(r[j++][1]+1);
    //         ans[ind[i]]=j-sum(p[ind[i]][1]);
    //     }
    //     return ans;
    // }
    constexpr int static n = 101;
    int bt[n + 1] = {};
    int prefix_sum(int i)
    {
        int sum = 0;
        for (i = i + 1; i > 0; i -= i & (-i))
            sum += bt[i];
        return sum;
    }
    void add(int i, int val = 1)
    {
        for (i = i + 1; i <= n; i += i & (-i))
            bt[i] += val;
    }
    vector<int> countRectangles(vector<vector<int>>& rects, vector<vector<int>>& points) {
        vector<int> idx(points.size()), res(points.size());
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int a, int b){ return points[a][0] > points[b][0];});
        sort(begin(rects), end(rects), [](const auto &r1, const auto &r2){ return r1[0] > r2[0];});
        for (int i = 0, j = 0; i < idx.size(); ++i) {
            while (j < rects.size() && rects[j][0] >= points[idx[i]][0])
                add(rects[j++][1] + 1);
            res[idx[i]] = j - prefix_sum(points[idx[i]][1]);
        }
        return res;
    }
};
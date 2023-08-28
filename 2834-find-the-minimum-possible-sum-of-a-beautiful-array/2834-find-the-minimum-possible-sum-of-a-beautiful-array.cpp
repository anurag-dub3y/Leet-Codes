class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<long long> vis;
        long long i=1;
        long long sum=0;
        while(vis.size()!=n){
            while(target-i>0 and vis.count(target-i)){ i++; }
            sum+=i;
            vis.insert(i++);
        }
        return sum;
    }
};



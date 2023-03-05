class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int r = time % n;
        int q = time / n;
        if(q%2){ return (n-r)+1; }
        return r+1;
    }
};

// 1 2 3 2 1
// 0 1 2 3 4
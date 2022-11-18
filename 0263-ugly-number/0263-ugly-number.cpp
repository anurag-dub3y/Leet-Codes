class Solution {
public:
    bool isUgly(int n) {
        if(n==0){ return false; }
        int x=n, y=n, z=n, a=0, b=0, c=0;
        while(x%2==0){ x/=2; a++; }
        while(y%3==0){ y/=3; b++; }
        while(z%5==0){ z/=5; c++; }
        // cout<<a<<' '<<b<<' '<<c<<endl;
        return pow(2,a)*pow(3,b)*pow(5,c)==n;
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int sum=accumulate(time.begin(),time.end(),0);
        int i=0, n=colors.size();
        while(i<n){
            int mx=time[i];
            while(i+1<n && colors[i]==colors[i+1]){
                i++;
                mx=max(mx,time[i]);
            }
            sum-=mx;
            i++;
        }
        return sum;
    }
};
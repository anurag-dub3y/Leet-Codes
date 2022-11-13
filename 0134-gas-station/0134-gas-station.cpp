class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), sum=0, start=0, curr=0;
        vector<int> req(n,0); // req[i] is cost of going from i to i+1
        for(int i=0; i<n; i++){
            req[i]=gas[i]-cost[i];
            sum+=req[i];
            curr+=req[i];
            if(curr<0){ curr=0; start=i+1; }
        }
        return sum<0?-1:start;        
    }
};
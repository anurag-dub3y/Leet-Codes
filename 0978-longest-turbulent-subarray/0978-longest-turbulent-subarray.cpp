class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans[100000][3],val = 1;
        ans[0][0] = ans[0][1] = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > arr[i-1]){
                ans[i][1] = ans[i-1][0] + 1;
                ans[i][0] = 1;
            }
            else if(arr[i] < arr[i-1]){
                ans[i][0] = ans[i-1][1] + 1;
                ans[i][1] = 1;
            }
            else{
                ans[i][0] = ans[i][1] = 1;
            }
             val = max({val,ans[i][0],ans[i][1]});
        }
        return val;
    }
};
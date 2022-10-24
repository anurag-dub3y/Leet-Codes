class Solution {
public:
    int sol=0;
    void backtrack(vector<string>& arr, vector<int>& count, int i, int &ans){
        if(i==arr.size()){
            sol=max(sol, ans);
            return;
        }
        backtrack(arr, count, i+1, ans);
        for(int k=0; k<arr[i].length(); k++){
            if(count[arr[i][k]-'a']>0){
                for(int j=0; j<k; j++){ count[arr[i][j]-'a']--; }
                return;
            }
            count[arr[i][k]-'a']++;
        }
        ans+=arr[i].length();
        backtrack(arr, count, i+1, ans);
        ans-=arr[i].length();
        for(int k=0; k<arr[i].length(); k++){
            count[arr[i][k]-'a']--;
        }
    }
    int maxLength(vector<string>& arr) {
        sol=0;
        int ans=0;
        vector<int> count(26, 0);
        backtrack(arr, count, 0, ans);
        return sol;
    }
};
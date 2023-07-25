class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq, formedSubsequence;
        
        // Formedsubsequence[i] is the number of subsequences of size>3 that end with i 
        for(auto &i:nums){ freq[i]++; }
        for(auto &i:nums){
            if(freq[i]==0){ continue; }
            else if(formedSubsequence[i-1]>0){
                freq[i]--;
                formedSubsequence[i-1]--;
                formedSubsequence[i]++;
            }
            else if(freq[i+1]>0 and freq[i+2]>0){
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                formedSubsequence[i+2]++;
            }
            else{ return false; }
        }
        return true;
    }
};
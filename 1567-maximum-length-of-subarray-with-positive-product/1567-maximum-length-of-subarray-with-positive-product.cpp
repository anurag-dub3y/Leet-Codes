class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int start=0, firstNeg=-1, neg=0, len=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                start=i+1; neg=0; firstNeg=-1;
            }
            else{
                if(nums[i]<0){ neg++; }
                if(neg==1 and firstNeg==-1){ firstNeg=i; }
                if(neg%2==0){ len=max(len,i-start+1); }
                else{ len=max(len,i-firstNeg); }
            }
        }
        return len;
    }
};
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int osum = 0, esum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0){ esum += nums[i]; }
            else{ osum += nums[i]; }
      }
      for(int i = 0; i < nums.size(); i++) {
          if(i % 2 == 0){ esum -= nums[i]; }
          else{ osum -= nums[i]; }
          if(osum == esum){ cnt++; }
          if(i % 2){ esum += nums[i]; }
          else{ osum += nums[i]; }
      }
      return cnt;

    }
};
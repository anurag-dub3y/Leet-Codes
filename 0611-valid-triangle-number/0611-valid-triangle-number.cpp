class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0;
        for(int i=nums.size()-1; i>=2; i--)  {
			for(int j=i-1; j>=1; j--) {
				auto itr=upper_bound(nums.begin(), nums.end(), nums[i]-nums[j]);  
				int ind=itr-nums.begin(); 
				if(ind<=j){ ans+=(j-ind); }
		    }   
        }   
        return ans;
    }
};
             

class Solution {
public:
    bool check(vector<int>& nums,vector<int>& v, int step, int val){
        if(step>=nums.size()){ return true; }
        int cur=nums[step];
        for(int i=0; i<v.size(); i++){
            if(cur+v[i]<=val){
                v[i]+=cur;
                if(check(nums,v,step+1,val)) return true;
                v[i]-=cur;
            }
            if(v[i]==0){ break; }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(begin(jobs),end(jobs));
        int minTime=jobs.back(), maxTime=accumulate(begin(jobs),end(jobs),0), ans;
        while(minTime<=maxTime){
            int midTime=(minTime+maxTime)/2;
            vector<int> v(k,0);
            if(check(jobs,v,0,midTime)){
                ans=midTime; maxTime=midTime-1;
            }
            else{ minTime=midTime+1;}
        }
        return ans;
    }
};
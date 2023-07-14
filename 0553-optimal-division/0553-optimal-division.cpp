class Solution {
public:
    // pair<string,double> find(int i, int j, int mode, vector<int>& nums){
    //     if(i==j){ return {to_string(nums[i]),nums[i]}; }
    //     else if(i+1==j){
    //         return {to_string(nums[i])+'/'+to_string(nums[i+1]),(double)nums[i]/nums[i+1]};
    //     }
    //     string ans=""; double mxVal;
    //     if(mode==0){
    //         mxVal=0;
    //         for(int k=i; k<j; k++){
    //             pair<string,double> i1=find(i,k,0,nums), i2=find(k+1,j,1,nums);
    //             double val=(double)i1.second/i2.second;
    //             if(val>mxVal){
    //                 ans=i1.first+'/';
    //                 if(k==j-1){ ans+=i2.first; }
    //                 else{ ans+="("+i2.first+")"; }
    //                 mxVal=val;
    //             }
    //         }
    //     }
    //     else{
    //         mxVal=1e18;
    //         for(int k=i; k<j; k++){
    //             pair<string,double> i1=find(i,k,0,nums), i2=find(k+1,j,1,nums);
    //             double val=(double)i1.second/i2.second;
    //             if(val<mxVal){
    //                 ans=i1.first+'/';
    //                 if(k==j-1){ ans+=i2.first; }
    //                 else{ ans+="("+i2.first+")"; }
    //                 mxVal=val;
    //             }
    //         }
    //     }
    //     return {ans,mxVal};
    // }
    string optimalDivision(vector<int>& nums) {
        string ans=to_string(nums[0]);
        if(nums.size()==1){ return ans; }
        else if(nums.size()==2){ return ans+'/'+to_string(nums[1]); }
        ans+='/';
        ans+='(';
        for(int i=1; i<nums.size()-1; i++){ ans+=to_string(nums[i])+'/'; }
        ans+=to_string(nums.back());
        ans+=')';
        return ans;
    }
};
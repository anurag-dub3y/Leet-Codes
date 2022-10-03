class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int> a(n,-1), b(n,-1), c(n+1,-1), d(n+1,-1);
        int i=0, j=0, sum=0, len=0, mxSum=0;
        while(i<n){
            sum+=nums[i]; len++;
            if(len>firstLen){ sum-=nums[j++]; len--; }
            if(len==firstLen){
                mxSum=max(mxSum,sum);
            }
            a[i]=(len==firstLen)?mxSum:-1;
            // cout<<'a'<<' '<<i<<' '<<a[i]<<endl;
            i++;
        }
        i=0, j=0, sum=0, len=0, mxSum=0;
        while(i<n){
            sum+=nums[i]; len++;
            if(len>secondLen){ sum-=nums[j++]; len--; }
            if(len==secondLen){
                mxSum=max(mxSum,sum);
            }
            b[i]=(len==secondLen)?mxSum:-1;
            // cout<<'b'<<' '<<i<<' '<<b[i]<<endl;
            i++;
        }
        i=n-1, j=n-1, sum=0, len=0, mxSum=0;
        while(i>=0){
            sum+=nums[i]; len++;
            if(len>firstLen){ sum-=nums[j--]; len--; }
            if(len==firstLen){
                mxSum=max(mxSum,sum);
            }
            c[i]=(len==firstLen)?mxSum:-1;
            // cout<<'c'<<' '<<i<<' '<<c[i]<<endl;
            i--;
        }
        i=n-1, j=n-1, sum=0, len=0, mxSum=0;
        while(i>=0){
            sum+=nums[i]; len++;
            if(len>secondLen){ sum-=nums[j--]; len--; }
            if(len==secondLen){
                mxSum=max(mxSum,sum);
            }
            d[i]=(len==secondLen)?mxSum:-1;
            // cout<<'d'<<' '<<i<<' '<<d[i]<<endl;
            i--;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(a[i]!=-1 && d[i+1]!=-1){ ans=max(ans,a[i]+d[i+1]); }
            if(b[i]!=-1 && c[i+1]!=-1){ ans=max(ans,b[i]+c[i+1]); }
        }
        return ans;
    }
};
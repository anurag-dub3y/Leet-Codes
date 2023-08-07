class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(), n=mat[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            // cout<<mid<<' '<<mat[mid][0]<<' '<<mat[mid][n-1]<<endl;
            if(mat[mid][0]>target){ high=mid-1; }
            else if(mat[mid][n-1]<target){ low=mid+1; }
            else{
                int mn=0, mx=n-1;
                while(mn<=mx){
                    int md=(mn+mx)/2;
                    // cout<<"-> "<<mid<<' '<<mat[mid][md]<<endl;
                    if(mat[mid][md]==target){ return true; }
                    else if(mat[mid][md]<target){ mn=md+1; }
                    else{ mx=md-1; }
                }
                return false;
            }
        }
        return false;
    }
};
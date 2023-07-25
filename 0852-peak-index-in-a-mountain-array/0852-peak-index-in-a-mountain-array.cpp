class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=1, high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid-1]<arr[mid] and arr[mid]<arr[mid+1]){ low=mid+1; }
            else if(arr[mid-1]>arr[mid] and arr[mid]>arr[mid+1]){ high=mid-1; }
            else{ return mid; }
        }
        return -1;
    }
};
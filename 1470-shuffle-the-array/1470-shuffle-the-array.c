

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int* ans = (int*) malloc(numsSize * sizeof(int));
    int j=0;
    for(int i=0; i<n; i++){
        // printf("%d %d\n",nums[i],nums[i+n]);
        ans[j]=nums[i];
        ans[j+1]=nums[i+n];
        j+=2;
    }
    // for(int i=0; i<2*n; i++){ printf("%d ",ans[i]); }
    *returnSize=numsSize;
    return ans;
}
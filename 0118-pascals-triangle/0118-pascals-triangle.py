class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans=[[1]]
        if(numRows==1):
            return ans
        for i in range(1,numRows):
            prev=ans[-1]
            temp=[1]
            j=1
            while(j<i):
                temp.append(prev[j-1]+prev[j])
                j+=1
            temp.append(1)
            ans.append(temp)
        return ans
        
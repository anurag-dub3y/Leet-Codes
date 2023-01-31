class Solution:
     def twoSum(self, nums, target):
        d = {}  # Initializing empty dictionary
        for i, n in enumerate(nums):    # Auto for loops
            m = target - n
            if m in d:                  # Find function 
                return [d[m], i]        # Return is same as C++
            else:
                d[n] = i
        
""" You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
"""

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        copy = nums[:]
        copy.sort()
        
        ans = []
        
        for n in nums:
            i = bisect.bisect_left(copy,n)
            copy.pop(i)
            ans.append(i)
        
        return ans

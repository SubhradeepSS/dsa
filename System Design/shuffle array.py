import random
class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.original=nums
        self.util=nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        nums=self.original
        return nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        #random.shuffle(self.util)
        return random.sample(self.util,len(self.util))


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()

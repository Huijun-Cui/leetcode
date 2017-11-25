class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for index1,i in enumerate(nums):
            for index2,j in enumerate(nums[index1+1:]):
                if i + j == target:
                    return [index1,index1+1+index2]
if __name__ == '__main__':
    d = Solution()
    result = d.twoSum([3, 2, 4,],6)
    print(result)
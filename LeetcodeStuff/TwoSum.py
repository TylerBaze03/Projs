class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)-1):
            t = (nums[i]+nums[i+1])
            if (t) == target:
                ans = []
                ans.append(i)
                ans.append(i+1)
                return ans

class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        ans = set()

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total == 0:
                    ans.add((nums[i], nums[left], nums[right]))
                    left += 1
                    right -= 1

                elif total < 0:
                    left += 1

                else:
                    right -= 1

        return [list(x) for x in ans]
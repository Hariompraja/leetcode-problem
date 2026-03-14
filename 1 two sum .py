# 1 two sum 
# Dificulty easy
# https://leetcode.com/problems/two-sum/

class Solution(object):
    def twoSum(self, nums, target):
        for i in range(0,len(nums)-1):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j] == target:
                    return [i,j]
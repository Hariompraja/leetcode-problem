// 268. Missing Number
// Dificulty easy
// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int totalSum = nums.size()*(nums.size() + 1)/2;

        for(int i = 0; i<nums.size(); i++)
        sum = sum+nums[i];
        int missingNumber = totalSum - sum;

        return missingNumber;
    }
};
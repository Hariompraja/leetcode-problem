class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {

            // Update the maximum height seen from both sides
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // Process the side with the smaller maximum height
            if (leftMax < rightMax) {
                water += leftMax - height[left];
                left++;
            } else {
                water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};
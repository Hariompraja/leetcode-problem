class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start == end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid);
        root->right = build(nums, mid + 1, end);
        return root;
    }
};
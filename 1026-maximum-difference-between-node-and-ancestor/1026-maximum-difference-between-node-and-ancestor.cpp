class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int minValue, int maxValue) {
        if (!node) return maxValue - minValue;

        minValue = min(minValue, node->val);
        maxValue = max(maxValue, node->val);

        int left = dfs(node->left, minValue, maxValue);
        int right = dfs(node->right, minValue, maxValue);

        return max(left, right);
    }
};
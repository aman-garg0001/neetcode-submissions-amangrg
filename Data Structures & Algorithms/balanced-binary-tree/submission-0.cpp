/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        bool ans = true;
        height(root, ans);
        return ans;
    }

    int height(TreeNode* node, bool &ans) {
        if (node == NULL) {
            return 0;
        }
        int lHeight = height(node->left, ans);
        int rHeight = height(node->right, ans);
        if (abs(lHeight-rHeight) > 1) {
            ans = false;
        }
        return max(lHeight, rHeight) + 1;
    }
};
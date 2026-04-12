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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        recc(root, ans);

        return ans;
    }

    int recc(TreeNode* node, int &ans) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = recc(node->left, ans);
        int rightHeight = recc(node->right, ans);
        ans = max(ans, rightHeight + leftHeight);
        return max(leftHeight, rightHeight) + 1;
    }
};

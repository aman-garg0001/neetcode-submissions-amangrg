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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        findDepth(root, ans, 1);
        return ans;
    }

    void findDepth(TreeNode* root, int &ans, int depth) {
        if (root == NULL) {
            return;
        }
        ans = max(ans, depth);
        findDepth(root->left, ans, depth + 1);
        findDepth(root->right, ans, depth + 1);
    }
};

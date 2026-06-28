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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        if (root == NULL) {
            return 0;
        }
        int maxNode = root->val;
        dfs(root, maxNode, ans);
        return ans;
    }

    void dfs(TreeNode* node, int maxNode, int &ans) {
        if (node == NULL) {
            return;
        }
        if (node->val >= maxNode) {
            ans++;
        }
        maxNode = max(maxNode, node->val);
        dfs(node->left, maxNode, ans);
        dfs(node->right, maxNode, ans);
    }
};
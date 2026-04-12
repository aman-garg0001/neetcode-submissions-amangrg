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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }
        return isIdentical(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL and subRoot == NULL) {
            return true;
        } else if (root == NULL or subRoot == NULL or root->val != subRoot->val) {
            return false;
        }

        return isIdentical(root->left, subRoot->left) and isIdentical(root->right, subRoot->right);
    }
};
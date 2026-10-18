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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        int preStart = 0;
        return constructSubTree(preStart, 0, size-1, inorder, preorder);
    }

private:
    TreeNode* constructSubTree(int &preStart, int inStart, int inEnd, vector<int> &inorder, vector<int> &preorder) {
        if (inStart >= inorder.size() or inEnd < 0 or preStart >= inorder.size() or inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        for (int i = inStart; i <= inEnd; i++) {
            if (preorder[preStart] == inorder[i]) {
                preStart++;
                root->left = constructSubTree(preStart, inStart, i-1, inorder, preorder);
                root->right = constructSubTree(preStart, i+1, inEnd, inorder, preorder);
                break;
            }
        }
        return root;
    }
};
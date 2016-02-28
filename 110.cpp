/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool balanceFlag;
    int getTreeDepth(TreeNode *root) {
        if (!root || !balanceFlag)
            return 0;
        int sz1 = getTreeDepth(root->left);
        int sz2 = getTreeDepth(root->right);
        if (abs(sz1 - sz2) > 1)
            balanceFlag = false;
        return max(sz1, sz2) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        balanceFlag = true;
        getTreeDepth(root);
        return balanceFlag;
    }
};

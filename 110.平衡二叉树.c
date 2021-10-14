/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {

    // 二叉树最大深度

    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// 平衡二叉树：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int leftDepth = maxDepth(root->left); // 记录当前的根的左树最大深度
    int rightDepth = maxDepth(root->right); // 记录当前的根的右数最大深度

    return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left)
        && isBalanced(root->right);

    // abs(leftDepth - rightDepth) < 2 : 当前树满足平衡二叉树条件
    // isBalanced(root->left) : 求解当前树的左子树是否满足平衡二叉树的条件
    // isBalansed(root->right) : 求解当前树的右子树是否满足平衡二叉树的条件
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // 二叉搜索树第K小的数
int cnt = 0;
int ans = 0;
void InOrder(struct TreeNode* root, int k) {
    if (root == NULL) {
        return;
    }
    InOrder(root->left, k);
    cnt++;
    if (cnt == k) {
        ans = root->val;
    }
    InOrder(root->right, k);
}
int kthSmallest(struct TreeNode* root, int k) {
    cnt = 0;
    InOrder(root, k);
    return ans;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {

    // ������������

    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

// ƽ���������һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int leftDepth = maxDepth(root->left); // ��¼��ǰ�ĸ�������������
    int rightDepth = maxDepth(root->right); // ��¼��ǰ�ĸ�������������

    return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left)
        && isBalanced(root->right);

    // abs(leftDepth - rightDepth) < 2 : ��ǰ������ƽ�����������
    // isBalanced(root->left) : ��⵱ǰ�����������Ƿ�����ƽ�������������
    // isBalansed(root->right) : ��⵱ǰ�����������Ƿ�����ƽ�������������
}
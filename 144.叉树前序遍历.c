// 求数的结点个数
int TreeSize(struct TreeNode* root) {
    return root == NULL ? 0 : TreeSize(root->left)
        + TreeSize(root->right) + 1;
}

void _PrevOrder(struct TreeNode* root, int* a, int* pi) {
    // 传参数的时候需要传索引i的地址 我们希望在递归过程中使用的索引i都是指的同一个值
    // 而不是在递归调用中栈帧里额外的数据拷贝
    if (root == NULL) {
        return;
    }

    a[*pi] = root->val;
    ++(*pi);

    _PrevOrder(root->left, a, pi);
    _PrevOrder(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * size);

    int i = 0;
    _PrevOrder(root, a, &i);

    *returnSize = size; // 返回型参数
    return a;
}
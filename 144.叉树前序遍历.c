// �����Ľ�����
int TreeSize(struct TreeNode* root) {
    return root == NULL ? 0 : TreeSize(root->left)
        + TreeSize(root->right) + 1;
}

void _PrevOrder(struct TreeNode* root, int* a, int* pi) {
    // ��������ʱ����Ҫ������i�ĵ�ַ ����ϣ���ڵݹ������ʹ�õ�����i����ָ��ͬһ��ֵ
    // �������ڵݹ������ջ֡���������ݿ���
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

    *returnSize = size; // �����Ͳ���
    return a;
}
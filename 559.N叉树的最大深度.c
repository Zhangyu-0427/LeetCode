/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int ans = 0;
void dfs(struct Node* root, int cur) {
    if (!root) return;
    ans = fmax(cur, ans);
    for (int i = 0; i < root->numChildren; i++) {
        dfs(root->children[i], cur + 1);
    }
}
int maxDepth(struct Node* root) {
    ans = 0;
    dfs(root, 1);
    return ans;
}
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
void dfs(TreeNode * root , int & res , int num)
{
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL)
    {
        num = num*10 + root->val;
        res += num;
        return;
    }
    num = num*10 + root->val;
    dfs(root->left , res , num);
    dfs(root->right , res , num);
}
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int num = 0;
        dfs(root , res , num);
        return res;
    }
};
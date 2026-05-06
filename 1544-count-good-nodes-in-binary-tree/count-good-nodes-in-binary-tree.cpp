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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);        
    }

    int dfs(TreeNode* root, int latestMax){
        if(!root) return 0;
        int newMax = max(latestMax, root->val);
        return (latestMax<= root->val) + dfs(root->left,newMax) + dfs(root->right, newMax);
    }
};
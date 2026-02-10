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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        extractInOrder(root, sortedValues);

        return buildBalanced(sortedValues, 0, sortedValues.size()-1);
        
    }

    void extractInOrder(TreeNode* node, vector<int>& sortedValues){
        if(!node) return;

        extractInOrder(node->left, sortedValues);
        sortedValues.push_back(node->val);
        extractInOrder(node->right, sortedValues);
    }

    TreeNode* buildBalanced(vector<int>& values, int start, int end){
        if( start > end) return nullptr;

        int mid = start + (end-start)/2;

        TreeNode* newNode = new TreeNode(values[mid]);

        newNode->left = buildBalanced(values, start, mid-1);
        newNode->right = buildBalanced(values, mid+1, end);

        return newNode;

    }
};
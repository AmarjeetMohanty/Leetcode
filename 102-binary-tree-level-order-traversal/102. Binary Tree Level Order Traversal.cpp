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
    vector<vector<int>> result;

    void solve(TreeNode* root, int depth){

        if(root==NULL) return;

        if(result.size() == depth)
            result.push_back(vector<int>());

        result[depth].push_back(root->val);
        solve(root->left, depth+1);
        solve(root->right, depth+1);
               
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root, 0);
        return result;
    }
};
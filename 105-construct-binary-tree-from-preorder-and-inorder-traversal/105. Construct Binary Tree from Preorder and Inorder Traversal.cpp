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

    TreeNode* build(vector <int> &preorder, vector <int> &inorder, int i1, int j1, int i2, int j2, unordered_map <int, int> &mp){

        if(i1 > j1) return nullptr; //empty tree
        TreeNode* node = new TreeNode(preorder[i1], nullptr, nullptr);
        int i = mp[preorder[i1]];
        node->left = build(preorder, inorder, i1+1, i1+i-i2, i2, i-1,mp);
        node->right = build(preorder, inorder, i1+i-i2+1, j1, i+1, j2,mp);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = preorder.size();
        for(int i = 0; i<n ; i++){
            mp[inorder[i]] = i;
        }

        return build (preorder,inorder, 0, n-1, 0, n-1, mp);
    }
};
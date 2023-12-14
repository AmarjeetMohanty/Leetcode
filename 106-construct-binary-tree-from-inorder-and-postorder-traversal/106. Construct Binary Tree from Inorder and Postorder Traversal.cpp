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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int i1, int j1, int i2, int j2, unordered_map<int,int> & mp){
        // [i1,j1] start and end of the inorder traversal array of the subtree
        // [i2,j2] start and end of the postorder traversal array of the subtree
        if(j2<i2) return NULL;
        TreeNode* node = new TreeNode(postorder[j2], nullptr, nullptr);
        int i = mp[postorder[j2]];
        node->left=build(inorder, postorder, i1, i-1, i2, i2+i-i1-1, mp);
        node->right=build(inorder, postorder, i+1, j1,i2+i-i1, j2-1,mp);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //last element of postorder is the root;
        int n = postorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        return build(inorder, postorder, 0,n-1,0,n-1,mp);
    }
};
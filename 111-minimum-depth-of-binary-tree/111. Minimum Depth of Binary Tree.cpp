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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, int>>q;
        TreeNode* temp = root;
        int level = 1;
        q.push({temp,level});
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto it = q.front();
                TreeNode* node = it.first;
                int l = it.second;
                q.pop();
                if(node->left==NULL && node->right==NULL) return l;
                l++;
                if(node->left) q.push({node->left,l});
                if(node->right) q.push({node->right,l});
            }
        }
        return -1;
    }
};
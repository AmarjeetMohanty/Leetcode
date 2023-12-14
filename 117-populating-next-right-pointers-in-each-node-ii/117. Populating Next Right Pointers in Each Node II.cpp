/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
        Node* connect(Node* root) {
        if(!root){return NULL;}
        queue<Node *> q;
        root->next=NULL;
        q.push(root);
        while(!q.empty()){
            vector<Node*> v;
            int j = 0;
            int s=q.size();
            for(int i=0;i<s;++i){
                Node * temp = q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            for(j=0;j<v.size()-1;++j){
                v[j]->next = v[j+1];
            }
            v[j]=NULL;
        }
        return root;
    };
};
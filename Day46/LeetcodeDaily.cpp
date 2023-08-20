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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root->left == NULL && root->right == NULL){
            if(key == root->val){
                return NULL;
            }
            return root;
        }

        if(root->val == key){
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            if(leftNode == NULL) return rightNode;
            else if(rightNode == NULL) return leftNode;
            
            TreeNode* temp = rightNode;
            while(rightNode->left != NULL) rightNode = rightNode->left;
            rightNode->left = leftNode;
            return temp;
        }
        TreeNode* node = NULL;
        if(key<root->val){
            node = deleteNode(root->left , key);
            root->left = node;
        }else{
            node = deleteNode(root->right , key);
            root->right = node;
        }
            return root;
    }
};
// Maximum Depth Of Binary Tree
// Given a binary tree, find its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
int maxDepth(Node *root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }
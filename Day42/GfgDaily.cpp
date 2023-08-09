// Kth Ancestor in a Tree
// Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.
bool solve(Node* root , int node , int &k , int &val){
    if(root == NULL) return false;
    if(root->data == node) return true;
    
    bool left = solve(root->left , node , k , val);
    if(left == true){
        if(val != 1e9) return true;
        k--;
        if(k == 0){
            val = root->data;
        }
        return true;
    }
    
    bool right = solve(root->right , node , k , val);
    if(right == true){
        if(val != 1e9) return true;
        k--;
        if(k == 0){
            val = root->data;
        }
        return true;
    }
    
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    int val = 1e9;
    
    bool get = solve(root , node , k ,val);
    if(get == false || val == 1e9) return -1;
    return val;
}
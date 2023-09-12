bool search(Node* root, int x) {
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL){
        if(root->data == x) return true;
        return false;
    }
    if(root->data == x) return true;
    bool tell = false;
    if(x > root->data) tell = search(root->right , x);
    else tell = search(root->left , x);
    return tell;
}
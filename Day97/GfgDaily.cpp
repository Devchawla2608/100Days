    int height(struct Node* node){
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return 1;
        return 1 + max(height(node->left) , height(node->right));
    }
    int height(struct Node* node){
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return 1;
        return 1 + max(height(node->left) , height(node->right));
    }
    
    int diameter(Node* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return max(
            (height(root->left) + height(root->right) + 1) , 
        max(diameter(root->left) , diameter(root->right)
        )
        );
    }